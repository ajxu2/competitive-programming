def c2(x):
    return x * (x - 1) >> 1

T = int(input())
for _ in range(T):
    a, b = map(int, input().split())
    d = b - a
    l, r = 0, 10**9
    while l < r:
        mid = (l + r + 1) >> 1
        if c2(mid) <= d:
            l = mid
        else:
            r = mid - 1
    print(l)
