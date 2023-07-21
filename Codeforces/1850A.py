for i in range(int(input())):
    a = sorted(list(map(int, input().split())))
    print("YES" if a[-1] + a[-2] >= 10 else "NO")
