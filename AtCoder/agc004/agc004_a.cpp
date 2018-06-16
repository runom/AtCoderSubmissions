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
    long long a, b, c;
    cin >> a >> b >> c;

    cout << min({abs(a / 2 * b * c - (a - a / 2) * b * c),
                 abs(b / 2 * a * c - (b - b / 2) * a * c),
                 abs(c / 2 * b * a - (c - c / 2) * b * a)})
         << endl;
    ;
}