MOD = 10**9 + 7

T = int(input())
for _ in range(T):
    n = int(input())
    a = [*map(int, input().split())]
    sumsq = sum(i**2 for i in a)
    sqsum = sum(a)**2
    huh = n * (n - 1)
    print((sqsum - sumsq) * pow(huh, -1, MOD) % MOD)
