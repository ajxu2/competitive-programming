from itertools import accumulate

def solve():
    n, q = map(int, input().split())
    a, b = input(), input()
    aps = [[0] + list(accumulate(1 if j == chr(i) else 0 for j in a)) for i in range(ord('a'), ord('z') + 1)]
    bps = [[0] + list(accumulate(1 if j == chr(i) else 0 for j in b)) for i in range(ord('a'), ord('z') + 1)]
    for i in range(q):
        l, r = map(int, input().split())
        ans = 0
        for j in range(26):
            acnt = aps[j][r] - aps[j][l-1]
            bcnt = bps[j][r] - bps[j][l-1]
            ans += max(0, acnt - bcnt)
        print(ans)

T = int(input())
for i in range(T):
    solve()
