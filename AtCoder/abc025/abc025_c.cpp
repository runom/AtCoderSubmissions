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

typedef long long ll;

int board[3][3];
int b[2][3];
int c[3][2];

pair<int, int> calc() {

  int x = 0, y = 0;

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (board[i][j] == board[i + 1][j]) {
        x += b[i][j];
      } else {
        y += b[i][j];
      }
    }
  }

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 2; ++j) {
      if (board[i][j] == board[i][j + 1]) {
        x += c[i][j];
      } else {
        y += c[i][j];
      }
    }
  }

  return make_pair(x, y);
}

pair<int, int> dfs(int x) {
  if (x == 9) {
    return calc();
  }

  pair<int, int> res(-1, -1);

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (board[i][j] == 0) {
        board[i][j] = (x & 1) + 1;

        auto ret = dfs(x + 1);

        if ((x % 2 == 0 && res.first < ret.first) ||
            (x % 2 == 1 && res.second < ret.second)) {
          res = ret;
        }

        board[i][j] = 0;
      }
    }
  }

  return res;
}

int main() {
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> b[i][j];
    }
  }

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 2; ++j) {
      cin >> c[i][j];
    }
  }

  auto res = dfs(0);

  cout << res.first << endl << res.second << endl;
}