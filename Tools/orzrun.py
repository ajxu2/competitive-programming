#!/usr/bin/env python3

from argparse import ArgumentParser
import re
import requests
from bs4 import BeautifulSoup
import json
from pathlib import Path
import run
from subprocess import CalledProcessError

GREEN = '\033[92m'
FAIL = '\033[91m'
BOLD = '\033[1m'
END = '\033[0m'

def owo(text, color):
    return f'{color}{text}{END}'

def cf_check_equality(text1, text2):
    ws_annihilator = re.compile(r'\s+')
    return ws_annihilator.sub(' ', text1) == ws_annihilator.sub(' ', text2)

def fetch_test_cases(problem):
    m = re.fullmatch(r'(\d+)([a-z]\d?)', problem, re.I)
    if not m:
        raise ValueError(f'Invalid Codeforces problem ID: {problem}')
    req = requests.get(f'https://mirror.codeforces.com/contest/{m.group(1)}/problem/{m.group(2)}', headers={'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64; rv:109.0) Gecko/20100101 Firefox/115.0'}) # trol
    b = BeautifulSoup(req.text, 'html.parser')

    # get input output pairs
    raw_inputs = b.find_all('div', attrs={'class': 'input'})
    raw_outputs = b.find_all('div', attrs={'class': 'output'})
    res = [tuple(j.pre.get_text('\n', strip=True) for j in i) for i in zip(raw_inputs, raw_outputs)]
    
    return res

def main():
    parser = ArgumentParser(description='Code runner that automatically fetches Codeforces samples')
    parser.add_argument('file', help='the file to orzrun')
    args = parser.parse_args()

    # retrieve the tests
    p = Path(args.file)
    tests_file = p.with_suffix(p.suffix + ':tests')
    if not tests_file.is_file():
        print('No tests file found, generating one.')
        test_cases = fetch_test_cases(p.stem.removeprefix('j_')) # removeprefix for java programs
        with tests_file.open('w') as f:
            json.dump(test_cases, f)
    with tests_file.open() as f:
        tests = json.load(f)

    # test the thing
    summary = ''
    try:
        run.compile_file(args.file, check=True)
    except CalledProcessError:
        return
    for cnt, (i, o) in enumerate(tests):
        process = run.run_no_compile(args.file, capture_output=True, input=i.encode())
        user_output = process.stdout.decode().strip()
        user_stderr = process.stderr.decode().strip()
        print(f'sample input:\n{i}\n\nsample output:\n{o}\n\nyour output:\n{user_output}\n')
        if user_stderr:
            print(f'your program wrote this on standard error:\n{user_stderr}\n')
        summary += f'Test #{cnt+1}: '
        if cf_check_equality(user_output, o):
            if process.returncode == 0:
                print(owo('OK\n', GREEN + BOLD))
                summary += owo('OK\n', GREEN + BOLD)
            else:
                print(f'exit code is {process.returncode}\n')
                print(owo('NOT OK\n', FAIL + BOLD))
                summary += owo('NOT OK\n', FAIL + BOLD)
        else:
            print(owo('NOT OK\n', FAIL + BOLD))
            summary += owo('NOT OK\n', FAIL + BOLD)

    print(f'summary:\n{summary}')

if __name__ == '__main__':
    main()
