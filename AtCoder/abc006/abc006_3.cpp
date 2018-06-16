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
    int n, m;
    cin >> n >> m;

    bool ok = false;
    for (int i = 0; i <= n; ++i) {
        int a = n - i;
        int b = m - i * 2;

        int j = 4 * a - b;
        int k = a - j;

        if (0 <= j && j <= a) {
            cout << i << ' ' << j << ' ' << k << endl;
            ok = true;
            break;
        }
    }

    if (!ok) {
        cout << -1 << ' ' << -1 << ' ' << -1 << endl;
    }
}