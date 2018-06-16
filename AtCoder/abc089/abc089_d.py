h, w, d = map(int, input().split())

a = [list(map(int, input().split())) for i in range(h)]

dic = [0] * (h * w)

for i in range(h):
    for j in range(w):
        dic[a[i][j] - 1] = i, j

s = [[0] * (h * w // d + (i < h * w % d)) for i in range(d)]

for i in range(d):
    for j in range(1, len(s[i])):
        b = i + d * (j - 1)
        c = i + d * j

        y, x = dic[b]
        ny, nx = dic[c]
        s[i][j] = s[i][j - 1] + abs(ny - y) + abs(nx - x)

q = int(input())

for i in range(q):
    l, r = map(int, input().split())
    l -= 1
    r -= 1
    print(s[l % d][r // d] - s[l % d][l // d])
