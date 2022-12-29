from argparse import ArgumentParser
import subprocess
from zipfile import ZipFile
from pathlib import Path
import time

GREEN = "\033[92m"
RED = "\033[91m"
END = "\033[0m"

parser = ArgumentParser(description="USACO-style grader for competitive programmers")
parser.add_argument("prog", help="the executable of your solution")
parser.add_argument("test_data", help="the zip file containing test data")
parser.add_argument("-tl", type=int, default=2, help="time limit in seconds (default: %(default)s)")

args = parser.parse_args()
prog = str(Path(Path.cwd(), args.prog))

with ZipFile(args.test_data) as f:
    data_files = f.namelist()
    i = 1
    while f"{i}.in" in data_files:
        # test this test case
        with f.open(f"{i}.in") as g:
            test_input = g.read()
        try:
            # start timer
            timing = time.perf_counter_ns()
            proc = subprocess.run([prog], input=test_input, capture_output=True, timeout=args.tl)
            timing = time.perf_counter_ns() - timing
        except subprocess.TimeoutExpired:
            print(f"Test {i:02} {RED}TLE{END}")
            i += 1
            continue
        timing = round(timing / 1000000)
        test_output = proc.stdout.decode().strip()
        # check if it is correct
        with f.open(f"{i}.out") as g:
            correct_output = g.read().decode().strip()
        if test_output == correct_output:
            print(f"Test {i:02} {GREEN}AC: {timing} ms{END}")
        elif proc.returncode != 0:
            print(f"Test {i:02} {RED}RTE{END}")
        elif test_output == "":
            print(f"Test {i:02} {RED}EMPTY{END}")
        else:
            print(f"Test {i:02} {RED}WA{END}")
        i += 1
