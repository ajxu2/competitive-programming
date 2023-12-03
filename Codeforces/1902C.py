# created: 12-03-2023 Sun 08:56 AM

import sys
input = sys.stdin.readline
print = lambda x: sys.stdout.write(str(x) + '\n')

import math

T = int(input())
for i in range(T):
    n = int(input())
    a = [*map(int, input().split())]
    if n == 1:
        print(1)
        continue
    m = max(a)
    g = math.gcd(*[m - i for i in a])
    def test(x):
        b = a[:]
        b.append(x)
        ans = 0
        m1 = max(b)
        for j in b:
            ans += (m1 - j) // g
        return ans
    a.sort()
    tmp = m
    for j in range(n-1, -1, -1):
        if tmp != a[j]:
            break
        tmp -= g
    print(min(test(tmp), test(m+g)))
