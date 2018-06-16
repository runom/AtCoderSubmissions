import fractions
import functools
n, k = map(int, input().split())
a = list(map(int, input().split()))
g = functools.reduce(fractions.gcd, a)

if max(a) >= k and k % g == 0:
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')