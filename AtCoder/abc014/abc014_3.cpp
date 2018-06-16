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

  int n;
  cin >> n;

  vector<int> sum(1000002);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    sum[a]++;
    sum[b + 1]--;
  }

  int maxi = sum[0];
  for (int i = 1; i < sum.size(); ++i) {
    sum[i] += sum[i - 1];
    maxi = max(maxi, sum[i]);
  }

  cout << maxi << endl;
}
