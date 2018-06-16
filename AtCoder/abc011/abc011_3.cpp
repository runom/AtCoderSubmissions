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
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;

    if (n == a || n == b || n == c) {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0; i < 100; ++i) {
        if (n - 3 <= 0) {
            cout << "YES" << endl;
            return 0;
        }

        if (!(n - 3 == a || n - 3 == b || n - 3 == c)) {
            n -= 3;
        } else if (!(n - 2 == a || n - 2 == b || n - 2 == c)) {
            n -= 2;
        } else if (!(n - 1 == a || n - 1 == b || n - 1 == c)) {
            n -= 1;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}