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

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (int i = 0; i < h; ++i) {
        cin >> a[i];
    }

    vector<vector<char>> red(h, vector<char>(w));
    auto blue = red;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            red[i][j] = blue[i][j] = '.';

            if (i == 0) {
                red[i][j] = '#';
            } else if (i == h - 1) {
                blue[i][j] = '#';
            } else {
                if (j % 2) {
                    red[i][j] = '#';
                } else {
                    blue[i][j] = '#';
                }
            }

            if (a[i][j] == '#') {
                red[i][j] = blue[i][j] = '#';
            }
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << red[i][j];
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << blue[i][j];
        }
        cout << endl;
    }
}