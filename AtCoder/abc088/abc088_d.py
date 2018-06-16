from collections import deque

h, w = map(int, input().split())
s = [input() for i in range(h)]

visited = [[0] * w for i in range(h)]

inf = 10 * w * h
dist = [[inf] * w for i in range(h)]

que = deque([(0, 0)])
visited[0][0] = 1
dist[0][0] = 0

dx = (1, -1, 0, 0)
dy = (0, 0, 1, -1)

while len(que) > 0:
    x, y = que.popleft()
    
    if x == w - 1 and y == h - 1:
        break
    
    for k in range(4):
        nx = x + dx[k]
        ny = y + dy[k]
        
        if 0 <= nx < w and 0 <= ny < h and s[ny][nx] == '.' and visited[ny][nx] == 0:
            que.append((nx, ny))
            visited[ny][nx] = 1
            dist[ny][nx] = dist[y][x] + 1

if dist[h - 1][w - 1] == inf:
    print(-1)
else:
    print(sum(s[i].count('.') for i in range(h)) - (dist[h - 1][w - 1] + 1))