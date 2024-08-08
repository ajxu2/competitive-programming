def solve():
    n = int(input())
    print(' '.join(map(str, [69] * n if n % 2 == 1 else [1] + [2] * (n - 2) + [3])))

T = int(input())
for i in range(T):
    solve()
