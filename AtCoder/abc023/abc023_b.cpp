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
  string s;
  cin >> n;
  cin >> s;

  if (s == "b") {
    cout << 0 << endl;
    return 0;
  }

  string t = "b";
  int ans = -1;
  for (int i = 1; t.size() < s.size(); ++i) {
    if (i % 3 == 1) {
      t.insert(t.begin(), 'a');
      t.insert(t.end(), 'c');
    } else if (i % 3 == 2) {
      t.insert(t.begin(), 'c');
      t.insert(t.end(), 'a');
    } else {
      t.insert(t.begin(), 'b');
      t.insert(t.end(), 'b');
    }
    if (t == s) {
      ans = i;
    }
  }

  cout << ans << endl;
}