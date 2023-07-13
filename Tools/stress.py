from argparse import ArgumentParser
import subprocess
from pathlib import Path, PurePath

parser = ArgumentParser(description="Stress tester for competitive programmers.")
parser.add_argument("your_sol", help="The executable of your solution.")
parser.add_argument("correct_sol", help="The executable of the correct solution.")
parser.add_argument("generator", help="The executable of the generator.")

args = parser.parse_args()

i = 1
while True:
    test_input = subprocess.run([Path(args.generator).absolute()], capture_output=True).stdout
    sol_output = subprocess.run([Path(args.your_sol).absolute()], input=test_input, capture_output=True).stdout
    correct_output = subprocess.run([Path(args.correct_sol).absolute()], input=test_input, capture_output=True).stdout
    if sol_output.decode().rstrip() == correct_output.decode().rstrip():
        print(f"Test {i} passed")
    else:
        print(f"The test case\n{test_input.decode()}\nproduced an incorrect result.\n\nYour output:\n{sol_output.decode().rstrip()}\n\nThe correct output:\n{correct_output.decode().rstrip()}")
        break
    i += 1
