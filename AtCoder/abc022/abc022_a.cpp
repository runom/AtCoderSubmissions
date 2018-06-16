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
  int n, s, t;
  cin >> n >> s >> t;
  int w = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    w += a;
    if (s <= w && w <= t) {
      ans++;
    }
  }

  cout << ans << endl;
}