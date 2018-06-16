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
  case 'i':
  case 'u':
  case 'e':
  case 'o':
    return true;

  default:
    return false;
  }
}

int main() {
  string s;
  cin >> s;

  for (char c : s) {
    if (!check(c)) {
      cout << c;
    }
  }
  cout << endl;
}