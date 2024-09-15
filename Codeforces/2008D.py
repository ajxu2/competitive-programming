class DSU:
    n, e, black = 0, [], []
    def __init__(self, n, black):
        self.n = n
        self.e = [-1] * n
        self.black = black[:]
    def find(self, x):
        if self.e[x] < 0:
            return x
        self.e[x] = self.find(self.e[x])
        return self.e[x]
    def unite(self, x, y):
        x, y = self.find(x), self.find(y)
        if x == y:
            return
        if -self.e[x] < -self.e[y]:
            x, y = y, x
        self.e[x] += self.e[y]
        self.black[x] += self.black[y]
        self.e[y] = x

T = int(input())
for _ in range(T):
    n = int(input())
    p = [int(i) - 1 for i in input().split()]
    s = [int(i) ^ 1 for i in input()]
    dsu = DSU(n, s)
    for i in range(n):
        dsu.unite(i, p[i])
    ans = [0] * n
    for i in range(n):
        ans[i] = dsu.black[dsu.find(i)]
    print(' '.join(map(str, ans)))
