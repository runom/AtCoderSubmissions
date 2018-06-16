#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int l = 0, r = 0;

  int ans = 0;
  int cnt = 0;
  while (true) {
    while (r < n && (a[r] == 1 || cnt < k)) {
      if (a[r] == 0)
        cnt++;
      r++;
      ans = max(ans, r - l);
    }

    if (r >= n)
      break;

    while (cnt == k) {
      if (a[l] == 0)
        cnt--;
      l++;
    }
  }

  cout << ans << endl;
}