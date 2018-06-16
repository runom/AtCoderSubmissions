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
    int deg, dis;
    cin >> deg >> dis;

    string dir[] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE",
                    "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};

    int x = (dis * 100 / 60 + 5) / 10;

    int w;
    if (x <= 2) {
        w = 0;
    } else if (x <= 15) {
        w = 1;
    } else if (x <= 33) {
        w = 2;
    } else if (x <= 54) {
        w = 3;
    } else if (x <= 79) {
        w = 4;
    } else if (x <= 107) {
        w = 5;
    } else if (x <= 138) {
        w = 6;
    } else if (x <= 171) {
        w = 7;
    } else if (x <= 207) {
        w = 8;
    } else if (x <= 244) {
        w = 9;
    } else if (x <= 284) {
        w = 10;
    } else if (x <= 326) {
        w = 11;
    } else {
        w = 12;
    }

    if (w == 0) {
        cout << "C" << ' ' << 0 << endl;
    } else {
        cout << dir[((deg * 10 + 1125) / 225 / 10) % 16] << ' ' << w << endl;
    }
}