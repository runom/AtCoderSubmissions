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
  int a[5];
  for (int i = 0; i < 5; ++i) {
    cin >> a[i];
  }

  int c[5] = {0, 0, 1, 1, 1};

  vector<int> res;
  do {
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
      sum += a[i] * c[i];
    }
    res.push_back(sum);
  } while (next_permutation(c, c + 5));

  sort(res.begin(), res.end(), greater<int>());

  cout << res[2] << endl;
}