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

class BIT {
public:
  BIT(int n) : n(n), data(n) {}

  int query(int i) const {
    int res = 0;

    while (i > 0) {
      res = std::max(res, get(i));
      i -= i & -i;
    }

    return res;
  }

  void update(int i, int x) {
    while (i <= n) {
      set(i, max(get(i), x));
      i += i & -i;
    }
  }

  int size() const { return n; }

private:
  int get(int i) const { return data[i - 1]; }

  void set(int i, int x) { data[i - 1] = x; }

private:
  int n;
  std::vector<int> data;
};

int LongestIncreasingSubsequence(const std::vector<int> &a) {
  std::vector<int> dp(a.size(), 1 << 28);
  for (int i = 0; i < a.size(); ++i) {
    *std::lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
  }
  return (std::lower_bound(dp.begin(), dp.end(), 1 << 28) - dp.begin());
}

int solve(vector<pair<int, int>> a) {
  sort(a.begin(), a.end(), [](auto x, auto y) {
    return x.first != y.first ? x.first < y.first : x.second > y.second;
  });

  vector<int> b(a.size());
  for (int i = 0; i < a.size(); ++i) {
    b[i] = a[i].second;
  }

  vector<int> dp(a.size());
  BIT bit(1e5 + 1);
  for (int i = 0; i < a.size(); ++i) {
    dp[i] = bit.query(b[i] - 1) + 1;
    bit.update(b[i], dp[i]);
  }

  return *max_element(dp.begin(), dp.end());
}

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }

  cout << solve(a) << endl;
}
