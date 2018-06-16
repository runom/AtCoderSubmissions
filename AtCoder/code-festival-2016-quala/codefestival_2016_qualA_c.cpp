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
    string s;
    cin >> s;
    int k;
    cin >> k;

    string ans;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'a') {
            ans += 'a';
            continue;
        }

        if (k >= 'z' - s[i] + 1) {
            ans += 'a';
            k -= 'z' - s[i] + 1;
        } else {
            ans += s[i];
        }
    }

    if (k > 0) {
        ans.back() = 'a' + (ans.back() - 'a' + (k % 26)) % 26;
    }

    cout << ans << endl;
}