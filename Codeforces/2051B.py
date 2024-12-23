# created: 12-22-2024 Sun 09:49 PM

import sys
input = sys.stdin.readline
print = lambda x: sys.stdout.write(str(x) + '\n')

T = int(input())
for _ in range(T):
    n, a, b, c = map(int, input().split())
    bruh = a + b + c
    ans = n // bruh * 3
    n -= ans // 3 * bruh
    if n <= 0:
        print(ans)
        continue
    n -= a
    ans += 1
    if n <= 0:
        print(ans)
        continue
    n -= b
    ans += 1
    if n <= 0:
        print(ans)
        continue
    n -= c
    ans += 1
    if n <= 0:
        print(ans)
        continue
