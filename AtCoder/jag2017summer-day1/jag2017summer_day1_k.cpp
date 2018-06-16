#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int64_t sum = 0;

    vector<pair<int64_t, int64_t>> a(n);
    for (auto& x : a) {
        cin >> x.first >> x.second;
        sum += x.second;
    }

    vector<int64_t> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = a[i].first + a[i].second;
    }

    sort(b.begin(), b.end());

    int i = 0;
    for (; i < n; ++i) {
        if (sum < b[i]) {
            break;
        } else {
            sum -= b[i];
        }
    }

    cout << i << endl;
}