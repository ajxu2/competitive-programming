from random import randint
from collections import Counter
from itertools import accumulate
import operator

def solve():
    n, m = map(int, input().split())
    hsh = [0] * n
    for i in range(m):
        l, r = map(int, input().split())
        rnd = randint(1, (1 << 63) - 1)
        hsh[l-1] ^= rnd
        hsh[r-1] ^= rnd
    print(n - Counter(accumulate(hsh, operator.xor)).most_common(1)[0][1])

T = int(input())
for i in range(T):
    solve()
