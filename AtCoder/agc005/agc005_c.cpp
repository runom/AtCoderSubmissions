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

    int dia = 0;
    vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
        dia = max(dia, a[i]);
    }

    for (int i = 0; i <= dia; ++i) {
        int k = max(i, dia - i);

        if (cnt[k] == 0) {
            cout << "Impossible" << endl;
            return 0;
        } else {
            cnt[k]--;
        }
    }

    for (int i = 1; i < dia; ++i) {
        int k = max(i, dia - i);

        cnt[k + 1] = 0;
    }

    for (int i = 0; i < cnt.size(); ++i) {
        if (cnt[i] > 0) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    cout << "Possible" << endl;
}