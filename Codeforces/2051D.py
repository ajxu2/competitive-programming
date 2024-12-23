# created: 12-22-2024 Sun 10:06 PM

import sys
input = sys.stdin.readline
print = lambda x: sys.stdout.write(str(x) + '\n')

import bisect

T = int(input())
for _ in range(T):
    n, x, y = map(int, input().split())
    a = [*sorted(map(int, input().split()))]
    ans = 0
    bruh = sum(a)
    for i in range(n):
        # other thing in range [sum(a) - a[i] - y, sum(a) - a[i] - x]
        lo, hi = bruh - a[i] - y, bruh - a[i] - x
        ans += bisect.bisect_right(a, hi, i + 1) - bisect.bisect_left(a, lo, i + 1)
    print(ans)
