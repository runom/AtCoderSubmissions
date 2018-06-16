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

typedef long long ll;

int main() {
  int n, d, k;
  cin >> n >> d >> k;

  vector<int> l(d), r(d);

  for (int i = 0; i < d; ++i) {
    cin >> l[i] >> r[i];
  }

  vector<int> s(k), t(k);

  for (int i = 0; i < k; ++i) {
    cin >> s[i] >> t[i];
  }

  for (int i = 0; i < k; ++i) {
    int a = s[i], b = s[i];

    for (int j = 0; j < d; ++j) {
      if (b < l[j] || r[j] < a) {
        continue;
      }

      a = min(a, l[j]);
      b = max(b, r[j]);

      if (a <= t[i] && t[i] <= b) {
        cout << j + 1 << endl;
        break;
      }
    }
  }
}