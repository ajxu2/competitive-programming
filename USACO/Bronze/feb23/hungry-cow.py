n, t = map(int, input().split())
a = []
for i in range(n):
    d, b = map(int, input().split())
    if a == [] or d >= a[-1][0] + a[-1][1]:
        a.append([d, b])
    else:
        a[-1][1] += b
ans = 0
for i in a:
    if i[0] + i[1] > t:
        ans += t - i[0] + 1
        break
    ans += i[1]
print(ans)
