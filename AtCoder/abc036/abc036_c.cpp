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

  vector<int> a(n), b;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  b = a;

  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  unordered_map<int, int> m;

  for (int i = 0; i < b.size(); ++i) {
    m[b[i]] = i;
  }

  for (int i = 0; i < n; ++i) {
    cout << m[a[i]] << endl;
  }
}