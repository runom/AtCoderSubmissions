#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> P;

const int inf = 1 << 28;

int main() {

  ios_base::sync_with_stdio(false);

  int h, w, t;
  cin >> h >> w >> t;

  char m[10][10];

  int sx, sy, gx, gy;

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> m[i][j];

      if (m[i][j] == 'S') {
        sx = j;
        sy = i;
      }

      if (m[i][j] == 'G') {
        gx = j;
        gy = i;
      }
    }
  }

  int d[21][11][11];

  fill((int *)d, (int *)(d + 21), inf);

  d[0][sy][sx] = 0;
  queue<tuple<int, int, int>> que;
  que.emplace(0, sy, sx);

  const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

  while (!que.empty()) {
    auto cur = que.front();
    que.pop();

    int cnt = get<0>(cur);
    int y = get<1>(cur);
    int x = get<2>(cur);

    if (x == gx && y == gy)
      continue;

    for (int k = 0; k < 4; ++k) {
      int nx = x + dx[k], ny = y + dy[k];

      if (0 <= nx && nx < w && 0 <= ny && ny < h) {
        if (m[ny][nx] != '#') {
          if (d[cnt][ny][nx] == inf) {
            d[cnt][ny][nx] = d[cnt][y][x] + 1;
            que.emplace(cnt, ny, nx);
          }
        } else {
          if (d[cnt + 1][ny][nx] == inf) {
            d[cnt + 1][ny][nx] = d[cnt][y][x];
            que.emplace(cnt + 1, ny, nx);
          }
        }
      }
    }
  }

  int ans = 1;
  for (int i = 1; i < w + h; ++i) {
    if (d[i][gy][gx] == inf)
      continue;

    int x = (t - d[i][gy][gx]) / i;
    ans = max(ans, x);
  }

  cout << ans << endl;
}
