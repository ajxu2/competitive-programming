for i in range(int(input())):
    n, k = map(int, input().split())
    a = sorted(list(map(int, input().split())))
    b = [i for i in range(n-1) if a[i+1] - a[i] > k]
    if len(b) == 0:
        print(0)
    else:
        mn = min(b[-1] + 1, n - b[0] - 1)
        if len(b) > 1:
            mn = min(mn, min(n-j+i for i, j in zip(b, b[1:])))
        print(mn)
