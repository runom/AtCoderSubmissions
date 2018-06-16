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
  cin >> n;
  map<string, int> m;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    m[s]++;
  }

  int maxi = 0;
  string ans;
  for (auto &p : m) {
    if (p.second > maxi) {
      maxi = p.second;
      ans = p.first;
    }
  }
  cout << ans << endl;
}