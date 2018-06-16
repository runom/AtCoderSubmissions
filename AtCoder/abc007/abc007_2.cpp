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
  if (s.size() != 1) {
    s.pop_back();
    cout << s << endl;
  } else {
    if (s != "a") {
      cout << "a" << endl;
    } else {
      cout << -1 << endl;
    }
  }
}