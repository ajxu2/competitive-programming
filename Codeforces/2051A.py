# created: 12-22-2024 Sun 09:44 PM

import sys
input = sys.stdin.readline
print = lambda x: sys.stdout.write(str(x) + '\n')

T = int(input())
for _ in range(T):
    n = int(input())
    a = [*map(int, input().split())]
    b = [*map(int, input().split())]
    ans = a[-1]
    for i in range(n-1):
        if a[i] - b[i+1] > 0:
            ans += a[i] - b[i+1]
    print(ans)
