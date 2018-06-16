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

vector<vector<int>> b;

int dfs(int x) {
  if (b[x].empty()) {
    return 1;
  }

  int mini = 1 << 28, maxi = 0;

  for (int y : b[x]) {
    int z = dfs(y);
    mini = min(mini, z);
    maxi = max(maxi, z);
  }

  return mini + maxi + 1;
}

int main() {
  int n;
  cin >> n;

  b.resize(n);

  for (int i = 1; i < n; ++i) {
    int x;
    cin >> x;
    b[x - 1].push_back(i);
  }

  cout << dfs(0) << endl;
}