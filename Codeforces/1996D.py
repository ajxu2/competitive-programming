def solve():
    n, x = map(int, input().split())
    ans = 0
    for a in range(1, n + 1):
        for b in range(1, n // a + 1):
            ans += max(0, min((n - a * b) // (a + b), x - a - b))
    print(ans)

T = int(input())
for i in range(T):
    solve()
