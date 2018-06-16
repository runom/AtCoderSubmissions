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
    int t, n, m;
    cin >> t;

    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    cin >> m;
    vector<int> b(m);
    for (auto& x : b) cin >> x;

    bool ok = true;

    int s = 0;
    for (int i = 0; i < m; ++i) {
        while (s < n && (b[i] - a[s]) > t) {
            s++;
        }

        if (s == n || a[s] > b[i]) {
            ok = false;
            break;
        }

        s++;
    }

    cout << (ok ? "yes" : "no") << endl;
}