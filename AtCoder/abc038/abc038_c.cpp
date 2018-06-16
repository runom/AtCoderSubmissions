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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  long long ans = 0;
  for (int i = 0; i < n;) {
    long long cnt;
    for (cnt = 1; i + cnt < n; ++cnt) {
      if (a[i + cnt] <= a[i + cnt - 1]) {
        break;
      }
    }
    ans += cnt * (cnt + 1) / 2;
    i += cnt;
  }

  cout << ans << endl;
}