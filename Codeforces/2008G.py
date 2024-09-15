from math import gcd

T = int(input())
for _ in range(T):
    n, k = map(int, input().split())
    a = [*map(int, input().split())]
    if n == 1:
        print(k if k > a[0] else k - 1)
        continue
    g = gcd(*a)
    if k > (n - 1) * (g - 1):
        print(k + n - 1)
    else:
        huh, off = divmod(k - 1, g - 1)
        print(huh * g + off + 1)
