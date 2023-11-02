# created: 10-25-2023 Wed 07:16 PM

from fractions import Fraction

n = int(input())
a = [*map(int, input().split())]
ans = Fraction('0')
for i in range(n):
    for j in range(i+1, n):
        cnt = 0
        for k in range(1, a[i] + 1):
            cnt += min(k - 1, a[j])
        ans += Fraction(cnt, a[i] * a[j])

ans = float(round(ans, 6))
print(f'{ans:.6f}')
