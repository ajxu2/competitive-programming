MOD = 10**9 + 7

def solve():
    s = input()
    n = len(s)
    p = {0: 1}
    cur = 0
    ans = 0
    for i in range(n):
        cur += 1 if s[i] == '1' else -1
        if cur not in p:
            p[cur] = 0
        ans += (n - i) * p[cur]
        ans %= MOD
        p[cur] += i + 2
    print(ans)

T = int(input())
for i in range(T):
    solve()
