# created: 12-22-2024 Sun 09:56 PM

import sys
input = sys.stdin.readline
print = lambda x: sys.stdout.write(str(x) + '\n')

T = int(input())
for _ in range(T):
    n, m, k = map(int, input().split())
    a = [*map(int, input().split())]
    q = [*map(int, input().split())]
    if k == n:
        print('1' * m)
    elif k == n-1:
        # find excluded
        excluded = n
        for i in range(k):
            if q[i] != i + 1:
                excluded = i + 1
                break
        print(''.join('1' if a[i] == excluded else '0' for i in range(m)))
    else:
        print('0' * m)
