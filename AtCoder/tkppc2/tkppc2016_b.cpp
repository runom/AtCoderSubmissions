#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> v(n), t(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i] >> t[i];
  }

  vector<vector<int>> dp(n + 1, vector<int>(m + 1));

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (j - t[i] >= 0) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i]] + v[i]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  cout << dp[n][m] << endl;
}