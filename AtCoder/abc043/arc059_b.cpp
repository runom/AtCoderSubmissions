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

pair<int, int> solve(const string &s) {
  for (int i = 0; i < s.size() - 1; ++i) {
    if (s[i] == s[i + 1]) {
      return make_pair(i + 1, i + 2);
    }
  }

  for (int i = 0; i < s.size() - 2; ++i) {
    if (s[i] == s[i + 2]) {
      return make_pair(i + 1, i + 3);
    }
  }

  return make_pair(-1, -1);
}

int main() {
  string s;
  cin >> s;

  auto ans = solve(s);

  cout << ans.first << ' ' << ans.second << endl;
}
