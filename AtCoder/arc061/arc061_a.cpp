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

typedef long long ll;

string s;

int main() {
    cin >> s;

    ll ans = 0;

    for (int i = 0; i < s.size(); ++i) {
        for (int j = 1; i + j <= s.size(); ++j) {
            ll n = stoll(s.substr(i, j));
            ll l = (i == 0 ? 1LL : (1LL << (i - 1)));
            ll r = (i + j == s.size() ? 1LL : 1LL << (s.size() - (i + j + 1)));
            ans += l * r * n;
        }
    }

    cout << ans << endl;
}