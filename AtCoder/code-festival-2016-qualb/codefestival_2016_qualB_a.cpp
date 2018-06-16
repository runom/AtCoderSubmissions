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
    string t = "CODEFESTIVAL2016";

    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != t[i]) {
            ans++;
        }
    }

    cout << ans << endl;
}