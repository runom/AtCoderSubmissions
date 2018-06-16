#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> child;
vector<int> val;
int ans;

int dfs(int node) {

  if (child[node].empty()) {
    return val[node];
  }

  int sum = 0;
  int mini = 1 << 28;
  for (int i = 0; i < child[node].size(); ++i) {
    int ret = dfs(child[node][i]);
    // cout << node << ' ' << ret << endl;
    sum += ret;
    mini = min(mini, ret);
  }

  // cout << node << ' ' << sum << ' ' << mini << endl;

  if (node != 0) {
    ans += sum - mini * child[node].size();
    return mini;
  } else {
    return ans + sum;
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  child.resize(n);

  for (int i = 1; i < n; ++i) {
    int par;
    cin >> par;
    child[par].push_back(i);
  }

  val.resize(n);
  for (int i = 0; i < m; ++i) {
    int b, c;
    cin >> b >> c;
    val[b] = c;
  }

  cout << dfs(0) << endl;
}