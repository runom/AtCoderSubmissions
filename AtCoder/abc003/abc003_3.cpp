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
    int n, k;
    cin >> n >> k;

    vector<int> r(n);
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }

    sort(r.begin(), r.end(), greater<int>());

    double sum = 0;
    double p = 2.0;
    for (int i = 0; i < k; ++i) {
        sum += r[i] / p;
        p *= 2.0;
    }

    cout << fixed << sum << endl;
}