for i in range(int(input())):
    n = int(input())
    a = [*map(int, input().split())]
    b = [0]*(n+1)
    m = {}
    for j in a:
        if j not in m:
            m[j] = 0
        m[j] += 1
    for j  in m:
        for k in range(j, n+1, j):
            b[k] += m[j]
    print(max(b[1:]))
