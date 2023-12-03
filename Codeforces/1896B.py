# created: 11-25-2023 Sat 08:56 AM

import sys
input = sys.stdin.readline
print = lambda x: sys.stdout.write(str(x) + '\n')

T = int(input())
for i in range(T):
    n = int(input())
    s = input()
    x = s.find('A')
    y = s.rfind('B')
    if x == -1 or y == -1 or x > y:
        print(0)
    else:
        print(y - x)
