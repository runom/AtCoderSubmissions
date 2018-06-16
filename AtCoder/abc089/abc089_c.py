n = int(input())

names = [input()[0] for i in range(n)]
prefix = 'MARCH'
cnt = [names.count(c) for c in prefix]

ans = 0
for i in range(5):
  for j in range(i + 1, 5):
    for k in range(j + 1, 5):
      ans += cnt[i] * cnt[j] * cnt[k]
      
print(ans)