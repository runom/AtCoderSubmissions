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

bool check(char c) {
  switch (c) {
  case 'a':
  case 't':
  case 'c':
  case 'o':
  case 'd':
  case 'e':
  case 'r':
    return true;

  default:
    return false;
  }
}

int main() {
  string s, t;
  cin >> s >> t;

  for (int i = 0; i < s.size(); ++i) {
    if (!(s[i] == t[i] || (s[i] == '@' && check(t[i])) ||
          (check(s[i]) && t[i] == '@') || (s[i] == '@' && t[i] == '@'))) {
      cout << "You will lose" << endl;
      return 0;
    }
  }
  cout << "You can win" << endl;
}