import sys
input = sys.stdin.readline
print = lambda x: sys.stdout.write(str(x)+"\n")

for i in range(int(input())):
    n = int(input())
    a = [*map(int, input().split())]
    b = [0]*(n+1)
    m = [0]*(n+1)
    for j in a:
        if j <= n:
            m[j] += 1
    for j in range(1, n+1):
        for k in range(j, n+1, j):
            b[k] += m[j]
    print(max(b[1:]))
