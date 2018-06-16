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
  int ans = 0;
  for (int i = 0; i < 3; ++i) {
    int s, e;
    cin >> s >> e;
    ans += s * e / 10;
  }
  cout << ans << endl;
}