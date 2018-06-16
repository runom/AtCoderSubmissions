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
 
template <typename T> T div_floor(T a, T b) {
  if (a > 0 && b > 0) {
    return (a + b - 1) / b;
  } else if (a < 0 && b < 0) {
    return (a + b + 1) / b;
  } else {
    return a / b;
  }
}
 
template <typename T> T div_ceil(T a, T b) {
  if (a < 0 && b > 0) {
    return (a - b + 1) / b;
  } else if (a > 0 && b < 0) {
    return (a - b - 1) / b;
  } else {
    return a / b;
  }
}
 
int main() {
  ios_base::sync_with_stdio(false);
 
  long long n, h;
  cin >> n >> h;
 
  long long a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
 
  long long mini = 1LL << 60;
  for (int i = 0; i <= n; ++i) {
 
    /*if ((b + e) * i + h > n * e) {
      mini = min(mini, a * i);
      continue;
    }*/
 
    // h + b * i + d * g > (n - i - g) * e
    // h + (b + e) * i + (d + e) * g > n * e
    //(d + e) * g > n * e - (h + (b + e) * i)
    // g > (n * e - (h + (b + e) * i)) / (d + e)
 
    long long g = div_ceil((n * e - (h + (b + e) * i)), (d + e)) + 1;
    mini = min(mini, a * i + c * max(0LL, g));
  }
 
  cout << mini << endl;
}