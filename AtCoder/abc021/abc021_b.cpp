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
  int a, b;
  int k;
  cin >> n >> a >> b >> k;

  bitset<101> city;

  city[a] = true;
  city[b] = true;

  for (int i = 0; i < k; ++i) {
    int p;
    cin >> p;
    if (city[p]) {
      cout << "NO" << endl;
      return 0;
    }
    city[p] = true;
  }

  cout << "YES" << endl;
}