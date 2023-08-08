import sys
input = sys.stdin.readline
print = lambda x: sys.stdout.write(str(x) + '\n')

T = int(input())
for i in range(T):
    n = int(input())
    a = [*map(int, input().split())]
    x = sum(a) - n
    y = a.count(1)
    print('YES' if x >= y and n != 1 else 'NO')
