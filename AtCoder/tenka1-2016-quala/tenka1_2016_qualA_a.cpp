#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
  int sum = 0;
  for (int i = 1; i <= 100; ++i) {
    if (i % 3 != 0 && i % 5 != 0) {
      sum += i;
    }
  }
  cout << sum << endl;
}