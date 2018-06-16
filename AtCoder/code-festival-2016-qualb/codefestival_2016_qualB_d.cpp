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

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int maxi = 0;
    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] <= maxi) continue;

        if (a[i] == maxi + 1) {
            maxi = maxi + 1;
            continue;
        }

        int m = (a[i] - 1) / (maxi + 1);

        ans += m;

        if (i == 0) {
            maxi = 1;
        }
    }

    cout << ans << endl;
}