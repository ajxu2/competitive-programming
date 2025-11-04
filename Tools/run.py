#!/usr/bin/env python3

from argparse import ArgumentParser
from subprocess import run, CalledProcessError
from pathlib import Path

def compile_file(file, **kwargs):
    p = Path(file)
    ext = p.suffix
    if ext == '.cpp':
        return run(['g++', '-std=c++23', '-O2', '-DLOCAL', '-Wall', '-Wextra', '-fsanitize=undefined', '-fsanitize=address', '-g', '-o', str(p.with_suffix('.out')), file], **kwargs)
    elif ext == '.java':
        return run(['javac', file], **kwargs)
    elif ext == '.py':
        pass
    elif ext == '.c':
        return run(['gcc', '-O2', '-DLOCAL', '-o', str(p.with_suffix('.out')), file], **kwargs)
    elif ext == '.rs':
        return run(['rustc', '-o', str(p.with_suffix('.out')), file], **kwargs)
    else:
        raise NotImplementedError

def run_no_compile(file, **kwargs):
    p = Path(file)
    ext = p.suffix
    if ext == '.cpp' or ext == '.c' or ext == '.rs':
        return run([str(p.with_suffix('.out').absolute())], env={'ASAN_OPTIONS': 'detect_leaks=0'}, **kwargs)
    elif ext == '.java':
        return run(['java', '-cp', str(p.parent), p.stem], **kwargs)
    elif ext == '.py':
        return run(['python3', file], **kwargs)
    else:
        raise NotImplementedError

def compile_and_run(file, **kwargs):
    try:
        compile_file(file, check=True, **kwargs)
    except CalledProcessError:
        return
    run_no_compile(file, **kwargs)

def main():
    parser = ArgumentParser(description='Compile and run programs')
    parser.add_argument('file', help='the file that you want to run')
    args = parser.parse_args()
    compile_and_run(args.file)

if __name__ == '__main__':
    main()
