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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;

  int ans = 1 << 28;

  for (int i = -100; i <= 100; ++i) {
    int sum = 0;
    for (int j = 0; j < n; ++j) {
      sum += (a[j] - i) * (a[j] - i);
    }
    ans = min(ans, sum);
  }

  cout << ans << endl;
}
