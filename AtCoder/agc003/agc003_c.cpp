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
    for (auto& x : a) {
        cin >> x;
    }

    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = {a[i], i};
    }
    sort(b.begin(), b.end());

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 != b[i].second % 2) {
            cnt++;
        }
    }

    cout << cnt / 2 << endl;
}