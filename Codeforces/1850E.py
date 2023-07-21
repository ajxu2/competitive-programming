from math import isqrt

for i in range(int(input())):
    n, c = map(int, input().split())
    s = [*map(int, input().split())]
    a, b, c = 4*n, 4*sum(s), sum(i*i for i in s) - c
    print((-b + isqrt(b*b-4*a*c)) // (2*a))
