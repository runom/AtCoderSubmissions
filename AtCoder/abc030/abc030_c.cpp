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
  int n, m;
  int x, y;
  cin >> n >> m >> x >> y;
  vector<int> a(n), b(m);

  for (int &x : a)
    cin >> x;
  for (int &x : b)
    cin >> x;

  int cnt = 0;
  int s = 0, t = 0;
  int u = 0, v;
  while (true) {
    bool end = false;

    while (a[s] < u) {
      s++;
      if (s == n) {
        end = true;
        break;
      }
    }

    if (end) {
      break;
    }

    v = a[s] + x;

    while (b[t] < v) {
      t++;
      if (t == m) {
        end = true;
        break;
      }
    }

    if (end) {
      break;
    }

    u = b[t] + y;

    cnt++;
  }

  cout << cnt << endl;
}