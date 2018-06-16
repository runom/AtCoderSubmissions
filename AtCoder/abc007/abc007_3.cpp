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

    int r, c;
    cin >> r >> c;

    char m[51][51];

    int sx, sy, gx, gy;
    cin >> sy >> sx >> gy >> gx;

    sy--;
    sx--;
    gy--;
    gx--;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> m[i][j];
        }
    }

    int d[51][51];

    fill((int *)d, (int *)(d + 51), inf);

    d[sy][sx] = 0;
    queue<tuple<int, int>> que;
    que.emplace(sy, sx);

    const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

    while (!que.empty()) {
        auto cur = que.front();
        que.pop();

        int y = get<0>(cur);
        int x = get<1>(cur);

        if (x == gx && y == gy) break;

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];

            if (0 <= nx && nx < c && 0 <= ny && ny < r) {
                if (m[ny][nx] != '#' && d[ny][nx] == inf) {
                    d[ny][nx] = d[y][x] + 1;
                    que.emplace(ny, nx);
                }
            }
        }
    }

    cout << d[gy][gx] << endl;
}