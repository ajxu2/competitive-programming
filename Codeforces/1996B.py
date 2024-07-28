def solve():
    n, k = map(int, input().split())
    for i in range(n):
        s = input()
        if i % k == 0:
            print(''.join(s[i] for i in range(0, n, k)))

T = int(input())
for i in range(T):
    solve()
