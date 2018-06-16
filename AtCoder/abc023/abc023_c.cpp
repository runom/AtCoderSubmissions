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

  int n;
  cin >> n;
  vector<int> a(n), b(n);
  vector<int> cnt1(r), cnt2(c);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    cnt1[a[i] - 1]++;
    cnt2[b[i] - 1]++;
  }

  vector<int> s(k + 1), t(k + 1);
  for (int i = 0; i < r; ++i) {
    if (cnt1[i] <= k) {
      s[cnt1[i]]++;
    }
  }

  for (int i = 0; i < c; ++i) {
    if (cnt2[i] <= k) {
      t[cnt2[i]]++;
    }
  }

  long long ans = 0;

  for (int i = 0; i <= k; ++i) {
    ans += (long long)(s[i]) * t[k - i];
  }

  for (int i = 0; i < n; ++i) {
    if (cnt1[a[i] - 1] + cnt2[b[i] - 1] == k + 1) {
      ans++;
    } else if (cnt1[a[i] - 1] + cnt2[b[i] - 1] == k) {
      ans--;
    }
  }

  cout << ans << endl;
}
