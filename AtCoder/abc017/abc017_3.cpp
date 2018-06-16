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
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  vector<int> l(n), r(n), s(n);
  vector<int> sum(m + 2);

  int all = 0;

  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i] >> s[i];
    sum[l[i]] += s[i];
    sum[r[i] + 1] -= s[i];
    all += s[i];
  }

  int mini = 1 << 28;
  for (int i = 1; i <= m; ++i) {
    sum[i] += sum[i - 1];
    mini = min(mini, sum[i]);
  }

  cout << all - mini << endl;
}
