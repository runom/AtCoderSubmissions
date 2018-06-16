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
  string s;
  cin >> s;
  string res;

  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != 'B') {
      res += s[i];
    } else if (!res.empty()) {
      res.pop_back();
    }
  }

  cout << res << endl;
}
