# created: 11-25-2023 Sat 08:49 AM

import sys
input = sys.stdin.readline
print = lambda x: sys.stdout.write(str(x) + '\n')

T = int(input())
for i in range(T):
    n = int(input())
    a = [*map(int, input().split())]
    print('YES' if a[0] == 1 else 'NO')
