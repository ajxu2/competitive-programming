#!/usr/bin/env python3

from argparse import ArgumentParser
from subprocess import run
from pathlib import Path

def compile_file(file):
    p = Path(file)
    ext = p.suffix
    if ext == ".cpp":
        run(["g++", "-std=c++17", "-O2", "-DLOCAL", "-fsanitize=undefined", "-o", str(p.with_suffix(".out")), file], check=True)
    elif ext == ".java":
        run(["javac", file], check=True)
    elif ext == ".py":
        pass
    else:
        raise NotImplementedError

def run_no_compile(file):
    p = Path(file)
    ext = p.suffix
    if ext == ".cpp":
        run([str(p.with_suffix(".out").absolute())])
    elif ext == ".java":
        run(["java", "-cp", str(p.parent), p.stem])
    elif ext == ".py":
        run(["python3", file])
    else:
        raise NotImplementedError

def run_and_compile(file):
    compile_file(file)
    run_no_compile(file)

def main():
    parser = ArgumentParser(description="Compile and run programs")
    parser.add_argument("file", help="the file that you want to run")
    args = parser.parse_args()
    run_and_compile(args.file)

if __name__ == "__main__":
    main()
