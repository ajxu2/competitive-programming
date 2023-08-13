import sys
input = lambda: sys.stdin.readline().strip()
print = lambda x: sys.stdout.write(str(x) + '\n')

T = int(input())
for i in range(T):
    n = int(input())
    a = [*map(int, input().split())]
    a.sort()
    if a[0] == a[-1]:
        print(-1)
    else:
        x = a.count(a[-1])
        b = a[:n-x]
        c = a[n-x:]
        print(f'{len(b)} {len(c)}')
        print(' '.join(map(str, b)))
        print(' '.join(map(str, c)))
