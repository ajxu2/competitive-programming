# created: 10-12-2023 Thu 10:01 AM

import sys
input = sys.stdin.readline
print = lambda x: sys.stdout.write(str(x) + '\n')

import math

T = int(input())
for i in range(T):
    a = [*map(int, input().split())]
    g = math.gcd(*a)
    print("YES" if sum(a) // g <= 6 else "NO")
