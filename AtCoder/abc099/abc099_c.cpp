#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, 1 << 20);

    dp[0] = 0;

    for(int i = 0; i < n; i++) {

        dp[i + 1] = min(dp[i + 1], dp[i] + 1);

        for(int j = 6; i + j <= n; j *= 6) {
            dp[i + j] = min(dp[i + j], dp[i] + 1);
        }

        for(int j = 9; i + j <= n; j *= 9) {
            dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
    }

    cout << dp[n] << endl;
}