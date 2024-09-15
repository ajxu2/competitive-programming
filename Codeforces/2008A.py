T = int(input())
for _ in range(T):
    a, b = map(int, input().split())
    if a == 0:
        print('YES' if b % 2 == 0 else 'NO')
    else:
        print('YES' if a % 2 == 0 else 'NO')
