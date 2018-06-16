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
    string s;
    cin >> s;

    int S = count(s.begin(), s.end(), 'S');
    int E = count(s.begin(), s.end(), 'E');
    int N = count(s.begin(), s.end(), 'N');
    int W = count(s.begin(), s.end(), 'W');

    if (!!S != !!N || !!W != !!E) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}