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
  ios_base::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  int a[5][5];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      cin >> a[i][j];
    }
  }

  vector<int> res(1);
  for (int i = 0; i < n; ++i) {
    vector<int> next;

    for (int j = 0; j < res.size(); ++j) {
      for (int l = 0; l < k; ++l) {
        next.push_back(res[j] ^ a[i][l]);
      }
    }

    swap(res, next);
  }

  for (int i = 0; i < res.size(); ++i) {
    if (res[i] == 0) {
      cout << "Found" << endl;
      return 0;
    }
  }

  cout << "Nothing" << endl;
}
