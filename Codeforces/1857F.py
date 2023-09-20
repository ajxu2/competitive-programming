from math import isqrt

T = int(input())
for i in range(T):
    n = int(input())
    a = [*map(int, input().split())]
    m = {}
    for j in a:
        if str(j) not in m:
            m[str(j)] = 0
        m[str(j)] += 1
    q = int(input())
    ans = [0] * q
    for j in range(q):
        b, c = map(int, input().split())
        b *= -1
        d = b*b - 4*c
        if d < 0 or isqrt(d)**2 != d:
            continue
        if d == 0:
            rt = -b // 2
            if str(rt) in m:
                ans[j] = m[str(rt)] * (m[str(rt)]-1) // 2
        else:
            rt1, rt2 = (-b + isqrt(d)) // 2, (-b - isqrt(d)) // 2
            if str(rt1) in m and str(rt2) in m:
                ans[j] = m[str(rt1)] * m[str(rt2)]
    print(' '.join(map(str, ans)))
