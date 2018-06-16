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
  int a, b, c;
  cin >> a >> b >> c;

  cout << (1 + (a < b) + (a < c)) << endl;
  cout << (1 + (b < a) + (b < c)) << endl;
  cout << (1 + (c < a) + (c < b)) << endl;
}