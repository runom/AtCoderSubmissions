n, p = map(int, input().split())
a = list(map(lambda x: x & 1, map(int, input().split())))

b, c = a.count(1), a.count(0)
d = 2 ** b // 2  * 2 ** c 
if p == 1:
    print(d)
else:
    print(2 ** n - d)