# created: 12-22-2024 Sun 10:19 PM

import sys
input = sys.stdin.readline
print = lambda x: sys.stdout.write(str(x) + '\n')

import bisect
import random
RANDOM = random.getrandbits(32)

T = int(input())
for _ in range(T):
    n, k = map(int, input().split())
    a = [*map(int, input().split())]
    b = [*map(int, input().split())]
    ab_antihash = [i ^ RANDOM for i in a + b]
    candidates = sorted(i ^ RANDOM for i in set(ab_antihash))
    a_s = sorted(a)
    b_s = sorted(b)
    ans = 0
    for i in candidates:
        bruh1 = n - bisect.bisect_left(b_s, i)
        bruh2 = n - bisect.bisect_left(a_s, i)
        if bruh1 - bruh2 <= k:
            ans = max(ans, bruh1 * i)
    print(ans)
