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

typedef long long ll;

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) {}
    bool unionSet(int x, int y) {
        x = root(x);
        y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) { return root(x) == root(y); }
    int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
    int size(int x) { return -data[root(x)]; }
};

int main() {
    int w, h;
    cin >> w >> h;

    vector<int> p(w), q(h);

    for (int i = 0; i < w; ++i) {
        cin >> p[i];
    }

    for (int i = 0; i < h; ++i) {
        cin >> q[i];
    }

    vector<pair<int, int>> all(w + h);
    for (int i = 0; i < w; ++i) {
        all[i].first = p[i];
        all[i].second = 0;
    }

    for (int i = 0; i < h; ++i) {
        all[i + w].first = q[i];
        all[i + w].second = 1;
    }

    ll ans = 0;

    int x = 0, y = 0;
    sort(all.begin(), all.end());

    for (int i = 0; i < all.size(); ++i) {
        if (all[i].second == 0) {
            ans += (ll)(all[i].first) * (h + 1 - y);
            x++;
        } else {
            ans += ll(all[i].first) * (w + 1 - x);
            y++;
        }
    }

    cout << ans << endl;
}