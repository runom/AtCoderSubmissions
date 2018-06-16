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

const double eps = 1e-8;

int main() {
    int a, b, c, d, t, v;
    cin >> a >> b >> c >> d >> t >> v;

    int n;
    cin >> n;

    bool f = false;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        f |= sqrt((a - x) * (a - x) + (b - y) * (b - y)) +
                 sqrt((c - x) * (c - x) + (d - y) * (d - y)) <=
             t * v + eps;
    }

    cout << (f ? "YES" : "NO") << endl;
}