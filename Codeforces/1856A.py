import sys
input = sys.stdin.readline
print = lambda x: sys.stdout.write(str(x) + '\n')

T = int(input())
for i in range(T):
    n = int(input())
    a = [*map(int, input().split())]
    if all(i <= j for i, j in zip(a, a[1:])):
        print(0)
    else:
        print(max(i if i > j else 0 for i, j in zip(a, a[1:])))
