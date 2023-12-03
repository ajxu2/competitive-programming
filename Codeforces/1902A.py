# created: 12-03-2023 Sun 08:33 AM

import sys
input = sys.stdin.readline
print = lambda x: sys.stdout.write(str(x) + '\n')

T = int(input())
for i in range(T):
    n = int(input())
    s = input().strip()
    if all(i == '1' for i in s):
        print('NO')
    else:
        print('YES')
