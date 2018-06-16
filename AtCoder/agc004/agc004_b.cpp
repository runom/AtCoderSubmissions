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

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<ll>> b(n, vector<ll>(n, 1LL << 60));
    for (int i = 0; i < n; ++i) {
        b[i][0] = a[i];
        for (int j = 1; j < n; ++j) {
            int c = (i - j + n) % n;
            b[i][j] = min(b[i][j - 1], a[c]);
        }
    }

    ll ans = 1LL << 60;
    for (int i = 0; i < n; ++i) {
        ll sum = x * i;
        for (int j = 0; j < n; ++j) {
            sum += b[j][i];
        }

        ans = min(ans, sum);
    }
    cout << ans << endl;
}