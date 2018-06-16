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

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> c(n);
    for (auto& x : c) cin >> x;

    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (c[i] % c[j] == 0) {
                d[i]++;
            }
        }
    }

    double ans = 0;

    for (int i = 0; i < n; ++i) {
        if (d[i] % 2 == 1) {
            ans += 0.5;
        } else {
            ans += (d[i] + 2.0) / (2.0 * d[i] + 2.0);
        }
    }

    cout << fixed << ans << endl;
}