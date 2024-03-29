#!/usr/bin/env python3

from argparse import ArgumentParser
from subprocess import CalledProcessError
import run
from pathlib import Path

GREEN = '\033[92m'
FAIL = '\033[91m'
BOLD = '\033[1m'
END = '\033[0m'

def owo(text, color):
    return f'{color}{text}{END}'

def main():
    parser = ArgumentParser(description='Stress tester for competitive programmers')
    parser.add_argument('your_sol', help='The executable of your solution')
    parser.add_argument('correct_sol', help='The executable of the correct solution')
    parser.add_argument('generator', help='The executable of the generator')
    args = parser.parse_args()

    try:
        run.compile_file(args.your_sol, check=True)
        run.compile_file(args.correct_sol, check=True)
        run.compile_file(args.generator, check=True)
    except CalledProcessError:
        return
    i = 1
    while True:
        test_input = run.run_no_compile(args.generator, capture_output=True).stdout.decode().strip()
        sol_output = run.run_no_compile(args.your_sol, input=test_input.encode(), capture_output=True).stdout.decode().strip()
        correct_output = run.run_no_compile(args.correct_sol, input=test_input.encode(), capture_output=True).stdout.decode().strip()
        if sol_output == correct_output:
            #print(f'Test {i} ' + owo('OK', GREEN))
            print(f'Test {i}, your output {sol_output}, correct output {correct_output}, ' + owo('OK', GREEN))
        else:
            print(f'The test case\n\n{test_input}\n\nproduced an incorrect result.\n\nYour output:\n{sol_output}\n\nThe correct output:\n{correct_output}')
            return
        i += 1

if __name__ == '__main__':
    main()
