a, b, c = sorted(map(int, input().split()))
if a % 2 == 0 and a == b and b == c:
    print(-1)
else:
    cnt = 0
    while a % 2 == 0 and b % 2 == 0 and c % 2 == 0:
        cnt = cnt + 1
        a, b, c = (b + c) //2, (a + c) // 2, (a + b) //2
    print(cnt)