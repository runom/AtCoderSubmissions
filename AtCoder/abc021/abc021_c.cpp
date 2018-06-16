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

int n, m;
vector<vector<int>> graph;

const int inf = 1 << 28;
const int mod = 1000000007;

int main() {

  ios_base::sync_with_stdio(false);

  cin >> n;
  graph.resize(n);

  int s, g;
  cin >> s >> g;
  s--;
  g--;

  cin >> m;

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;

    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  vector<int> d(n, inf), cnt(n);
  d[s] = 0;
  cnt[s] = 1;
  queue<int> que;
  que.push(s);

  while (!que.empty()) {
    int cur = que.front();
    que.pop();

    if (cur == g)
      break;

    for (int to : graph[cur]) {
      if (d[to] == inf) {
        d[to] = d[cur] + 1;
        cnt[to] = cnt[cur];
        que.push(to);
      } else if (d[to] == d[cur] + 1) {
        cnt[to] = (cnt[to] + cnt[cur]) % mod;
      }
    }
  }

  cout << cnt[g] % mod << endl;
}
