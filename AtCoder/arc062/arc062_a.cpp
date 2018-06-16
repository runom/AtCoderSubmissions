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
    int n;
    cin >> n;
    vector<ll> t(n), a(n);

    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> a[i];
    }

    long long x = 1, y = 1;

    for (int i = 0; i < n; ++i) {
        ll t0 = t[i], a0 = a[i];
        ll k0 = (x + t0 - 1) / t0, k1 = (y + a0 - 1) / a0;

        x = t0 * max(k0, k1);
        y = a0 * max(k0, k1);
    }

    cout << x + y << endl;
}