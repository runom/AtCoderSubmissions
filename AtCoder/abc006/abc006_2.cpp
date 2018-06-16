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

  vector<int> a(n + 1);
  a[1] = 0;
  a[2] = 0;
  a[3] = 1;

  for (int i = 4; i <= n; ++i) {
    a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % 10007;
  }

  cout << a[n] << endl;
}