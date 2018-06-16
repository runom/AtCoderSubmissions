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
  string s;
  cin >> s;

  for (int i = 0; i < s.size(); ++i) {
    switch (s[i]) {
    case 'o':
      break;
    case 'k':
      break;
    case 'u':
      break;
    case 'c':
      if (i + 1 < s.size() && s[i + 1] == 'h') {
        i++;
        break;
      }
    default:
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}