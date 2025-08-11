# created: 08-10-2025 Sun 12:03 PM

import sys
input = lambda: sys.stdin.readline().strip()
print = lambda x: sys.stdout.write(str(x) + '\n')

import collections

def reduce(L, k):
    d = collections.Counter()
    for i in L:
        j = i % k
        if j > k // 2:
            j = k - j
        d[j] += 1
    return d

def solve():
    n, k = map(int, input().split())
    S = [*map(int, input().split())]
    T = [*map(int, input().split())]
    print('YES' if reduce(S, k) == reduce(T, k) else 'NO')

T = int(input())
for _ in range(T):
    solve()
