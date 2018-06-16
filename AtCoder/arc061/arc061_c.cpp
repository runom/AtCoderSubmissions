#include <algorithm>
#include <bitset>
#include <cassert>
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
    int to;
    int c;
};

template <typename T, typename U>
U value_or(std::map<T, U>& m, T key, U val) {
    return m.count(key) ? m[key] : val;
}

const int inf = 1 << 28;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int p, q, c;
        cin >> p >> q >> c;
        p--;
        q--;
        graph[p].push_back((Edge){q, c});
        graph[q].push_back((Edge){p, c});
    }

    for (int i = 0; i < n; ++i) {
        sort(graph[i].begin(), graph[i].end(), [](auto& a, auto& b) {
            return a.c == b.c ? a.to < b.to : a.c < b.c;
        });
    }

    map<pair<int, int>, int> dist;
    dist[{0, -1}] = 0;

    deque<pair<int, int>> que;
    que.emplace_back(0, -1);
    while (!que.empty()) {
        auto cur = que.front();
        que.pop_front();

        if (cur.first == n - 1) {
            cout << dist[{cur.first, cur.second}] << endl;
            return 0;
        }

        int d = dist[cur];

        if (cur.second == -1) {
            for (auto& e : graph[cur.first]) {
                if (value_or(dist, {e.to, e.c}, inf) > d + 1) {
                    dist[{e.to, e.c}] = d + 1;
                    que.emplace_back(e.to, e.c);
                }
            }
        } else {
            auto r = equal_range(graph[cur.first].begin(),
                                 graph[cur.first].end(), (Edge){0, cur.second},
                                 [](auto& a, auto& b) { return a.c < b.c; });

            for (auto it = r.first; it != r.second; ++it) {
                auto e = *it;
                if (value_or(dist, {e.to, e.c}, inf) > d) {
                    dist[{e.to, e.c}] = d;
                    que.emplace_front(e.to, e.c);
                }
            }

            if (r.second - r.first != graph[cur.first].size()) {
                if (value_or(dist, {cur.first, -1}, inf) > d) {
                    dist[{cur.first, -1}] = d;
                    que.emplace_front(cur.first, -1);
                }
            }
        }
    }

    cout << -1 << endl;
}