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

int n, k;
vector<int> a;
vector<vector<int>> edges;

int ans;

int dfs(int x) {
    // cout << x << ' ' << cnt << endl;

    int h = 0;

    for (int to : edges[x]) {
        if (to == 0) continue;
        h = max(h, dfs(to));
    }

    if (a[x] == 0) return 0;
    if (h == k - 1 && a[x] != 0) {
        ans++;
        return 0;
    } else {
        return h + 1;
    }
}
int main() {
    cin >> n >> k;
    a.resize(n);
    edges.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
        edges[a[i]].push_back(i);
    }

    if (a[0] != 0) {
        ans++;
        a[0] = 0;
    }

    dfs(0);
    cout << ans << endl;
}