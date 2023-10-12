# created: 10-12-2023 Thu 09:53 AM

import sys
input = lambda: sys.stdin.readline().strip()
print = lambda x: sys.stdout.write(str(x) + '\n')

T = int(input())
for i in range(T):
    input()
    x = input()
    s = input()
    ans = 0
    found = False
    while ans <= 7:
        if s in x:
            found = True
            break
        x += x
        ans += 1
    if found:
        print(ans)
    else:
        print(-1)
