# created: 10-12-2023 Thu 10:17 AM

import sys
input = sys.stdin.readline
print = lambda x: sys.stdout.write(str(x) + '\n')

from collections import Counter

T = int(input())
for _ in range(T):
    n = int(input())
    a = [*map(int, input().split())]
    b = []
    for i in a:
        # prime factorize
        j = 2
        while j * j <= i:
            while i % j == 0:
                i //= j
                b.append(j)
            j += 1
        if i != 1:
            b.append(i)
    freq = Counter()
    for i in b:
        freq[str(i)] += 1
    print('YES' if all(i % n == 0 for i in freq.values()) else 'NO')
