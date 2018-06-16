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

struct Edge {
  int to, cost;
};

typedef pair<int, int> P;

int n, m;
vector<vector<Edge>> graph;

const int inf = 1 << 28;

int dijkstra(int x) {

  priority_queue<P, vector<P>, greater<P>> que;
  vector<int> d(n, inf);
  d[x] = 0;
  que.emplace(0, x);

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] < p.first)
      continue;
    for (auto &e : graph[v]) {
      if (v == x && e.to == 0)
        continue;

      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.emplace(d[e.to], e.to);
      }
    }
  }

  return d[0];
}

int main() {

  ios_base::sync_with_stdio(false);

  cin >> n >> m;

  graph.resize(n);

  for (int i = 0; i < m; ++i) {
    int u, v, l;
    cin >> u >> v >> l;
    u--;
    v--;

    graph[u].push_back({v, l});
    graph[v].push_back({u, l});
  }

  int mini = inf;
  for (auto &e : graph[0]) {
    int ret = dijkstra(e.to);
    mini = min(mini, e.cost + ret);
  }

  if (mini == inf) {
    cout << -1 << endl;
  } else {
    cout << mini << endl;
  }
}
