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

  int n;
  cin >> n;

  vector<int> a(n);
  set<int> b;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];

    while (!(a[i] & 1)) {
      a[i] >>= 1;
    }

    b.insert(a[i]);
  }

  cout << b.size() << endl;
}
