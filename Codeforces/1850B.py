for i in range(int(input())):
    n = int(input())
    mx = 0
    mxi = 0
    for j in range(n):
        a, b = map(int, input().split())
        if a <= 10 and b > mx:
            mx = b
            mxi = j+1
    print(mxi)
