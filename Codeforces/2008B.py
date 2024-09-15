from math import isqrt

def gen(x):
    bruh = [69] * (x ** 2)
    for i in range(x):
        if i == 0 or i == x - 1:
            for j in range(x):
                bruh[i*x+j] = 1
        else:
            for j in range(x):
                if j == 0 or j == x - 1:
                    bruh[i*x+j] = 1
                else:
                    bruh[i*x+j] = 0
    return ''.join(map(str, bruh))

def perf_sq(x):
    return isqrt(x) ** 2 == x

T = int(input())
for _ in range(T):
    n = int(input())
    s = input()
    print('Yes' if perf_sq(n) and s == gen(isqrt(n)) else 'No')
