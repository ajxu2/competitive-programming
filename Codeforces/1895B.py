# created: 11-17-2023 Fri 12:37 PM

import sys
input = sys.stdin.readline
print = lambda x: sys.stdout.write(str(x) + '\n')

T = int(input())
for i in range(T):
    n = int(input())
    a = [*map(int, input().split())]
    a.sort()
    x, y = a[:n], a[n:]
    print(x[-1] - x[0] + y[-1] - y[0])
    for i, j in zip(x, y):
        print(f'{i} {j}')
