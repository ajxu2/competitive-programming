from argparse import ArgumentParser
import subprocess
from pathlib import Path, PurePath

parser = ArgumentParser(description="Stress tester for competitive programmers.")
parser.add_argument("your_sol", help="The name of the executable of your solution.")
parser.add_argument("correct_sol", help="The name of the executable of the correct solution.")
parser.add_argument("generator", help="The name of the executable of the generator.")
parser.add_argument("--bindir", default=f"{str(Path.home()/'tmp')}", help="The directory that your executables are all located in (default: %(default)s).")

args = parser.parse_args()
BIN_PATH = args.bindir
SOL = str(PurePath(BIN_PATH, args.your_sol))
CORRECT = str(PurePath(BIN_PATH, args.correct_sol))
GEN = str(PurePath(BIN_PATH, args.generator))

i = 1
while True:
    test_input = subprocess.run([GEN], capture_output=True).stdout
    sol_output = subprocess.run([SOL], input=test_input, capture_output=True).stdout
    correct_output = subprocess.run([CORRECT], input=test_input, capture_output=True).stdout
    if sol_output.decode().rstrip() == correct_output.decode().rstrip():
        print(f"Test {i} passed")
    else:
        print(f"The test case\n{test_input.decode()}\nproduced an incorrect result.\n\nYour output:\n{sol_output.decode().rstrip()}\n\nThe correct output:\n{correct_output.decode().rstrip()}")
        break
    i += 1
