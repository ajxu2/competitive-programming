# created: 12-03-2023 Sun 08:47 AM

import sys
input = sys.stdin.readline
print = lambda x: sys.stdout.write(str(x) + '\n')

T = int(input())
for i in range(T):
    n, P, l, t = map(int, input().split())
    lo, hi = 1, n+1
    while lo < hi:
        mid = (lo + hi) // 2
        if mid * l + min(2 * mid, (n + 6) // 7) * t >= P:
            hi = mid
        else:
            lo = mid + 1
    print(n - lo)
