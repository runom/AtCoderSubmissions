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
    int n, a;
    cin >> n >> a;

    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    // i番目まででj枚使ってkになる個数
    static long long dp[51][51][2501] = {0};
    for (int i = 0; i <= n; ++i) {
        dp[i][0][0] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = a * n; k >= 0; --k) {
                if (k - x[i - 1] >= 0) {
                    dp[i][j][k] += dp[i - 1][j - 1][k - x[i - 1]];
                }
                dp[i][j][k] += dp[i - 1][j][k];
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        int target = a * i;

        ans += dp[n][i][target];
    }

    cout << ans << endl;
}