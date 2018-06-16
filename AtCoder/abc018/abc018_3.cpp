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

  ios_base::sync_with_stdio(false);

  int r, c, k;
  cin >> r >> c >> k;

  vector<string> s(r);
  for (int i = 0; i < r; ++i) {
    cin >> s[i];
  }

  vector<vector<int>> a(r, vector<int>(c));
  auto b = a;

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (s[i][j] == 'x') {
        a[i][j] = 0;
      } else {
        if (j == 0) {
          a[i][j] = 1;
        } else {
          a[i][j] = a[i][j - 1] + 1;
        }
      }
    }
  }

  for (int i = 0; i < r; ++i) {
    for (int j = c - 1; j >= 0; --j) {
      if (s[i][j] == 'x') {
        b[i][j] = 0;
      } else {
        if (j == c - 1) {
          b[i][j] = 1;
        } else {
          b[i][j] = b[i][j + 1] + 1;
        }
      }
    }
  }

  int ans = 0;

  for (int i = k - 1; i < r - k + 1; ++i) {
    for (int j = k - 1; j < c - k + 1; ++j) {
      bool f = true;

      for (int u = -(k - 1); u <= k - 1; ++u) {
        if (a[i + u][j] < k - abs(u) || b[i + u][j] < k - abs(u)) {
          f = false;
          break;
        }
      }

      if (f) {
        ans++;
      }
    }
  }

  cout << ans << endl;
}
