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

  for (int i = 0; i < s.size();) {
    int cnt;
    for (cnt = 1; i + cnt < s.size(); ++cnt) {
      if (s[i + cnt] != s[i])
        break;
    }
    cout << s[i] << cnt;

    i += cnt;
  }
  cout << endl;
}