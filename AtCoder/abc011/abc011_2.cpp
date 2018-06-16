#include <algorithm>
#include <bitset>
#include <cctype>
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

  cout << (char)(toupper(s[0]));
  for (int i = 1; i < s.size(); ++i) {
    cout << (char)(tolower(s[i]));
  }
  cout << endl;
}