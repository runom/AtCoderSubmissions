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

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    long long ans = 0;
    for (auto& x : a) {
        cin >> x;
    }

    for (int i = 0; i < n - 1; ++i) {
        ans += a[i] / 2;
        a[i] %= 2;
        if (a[i] && a[i + 1]) {
            ans++;
            a[i]--;
            a[i + 1]--;
        }
    }

    ans += a[n - 1] / 2;

    cout << ans << endl;
}