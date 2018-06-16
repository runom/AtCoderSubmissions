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
  int m;
  cin >> m;

  if (m < 100) {
    cout << "00" << endl;
  } else if (m < 1000) {
    cout << 0 << m / 100 << endl;
  } else if (m <= 5000) {
    cout << m / 100 << endl;
  } else if (m <= 30000) {
    cout << m / 1000 + 50 << endl;
  } else if (m <= 70000) {
    cout << (m / 1000 - 30) / 5 + 80 << endl;
  } else {
    cout << 89 << endl;
  }
}