# created: 10-12-2023 Thu 10:07 AM

import sys
input = sys.stdin.readline
print = lambda x: sys.stdout.write(str(x) + '\n')

T = int(input())
for _ in range(T):
    n = int(input())
    a = []
    for i in range(n):
        s = input()
        a.append([ord(i) for i in s])
    ans = 0
    for i in range(n//2):
        for j in range(n//2):
            b = [a[i][j], a[j][n-1-i], a[n-1-i][n-1-j], a[n-1-j][i]]
            ans += max(b) * 4 - sum(b)
    print(ans)
