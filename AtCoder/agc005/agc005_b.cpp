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

using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<ll> a(n);
    vector<ll> pos(n + 1);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    long long ans = 0;

    set<ll> s;
    s.insert(-1);
    s.insert(n);

    for (int i = 1; i <= n; ++i) {
        auto res = s.insert(pos[i]);

        ll l = *prev(res.first);
        ll r = *next(res.first);

        ans += (pos[i] - l) * (r - pos[i]) * i;
    }

    cout << ans << endl;
}