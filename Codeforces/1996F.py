def solve():
    n, k = map(int, input().split())
    a = [*map(int, input().split())]
    b = [*map(int, input().split())]
    l, r = 1, 10**9 + 1
    while l < r:
        mid = l + r >> 1
        geq = sum((i - mid) // j + 1 for i, j in zip(a, b) if mid <= i)
        if geq <= k:
            r = mid
        else:
            l = mid + 1
    taken = sum((i - l) // j + 1 for i, j in zip(a, b) if l <= i)
    ans = sum((num := (i - l) // j + 1) * (2 * i - (num - 1) * j) >> 1 for i, j in zip(a, b) if l <= i)
    ans += (l - 1) * (k - taken)
    print(ans)

T = int(input())
for i in range(T):
    solve()
