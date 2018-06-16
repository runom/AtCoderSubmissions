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
  ll n;
  cin >> n;

  int d = 0;
  for (ll x = n; x > 0; x /= 2) {
    d++;
  }

  int res = 0;
  ll x = 1;
  for (int i = 0; i < d; ++i) {
    if (d % 2 == i % 2) {
      x = x << 1;
    } else {
      x = (x << 1) | 1;
    }

    if (x > n) {
      res = (i & 1) ^ 1;
      break;
    }
  }

  cout << (res == 0 ? "Takahashi" : "Aoki") << endl;
}