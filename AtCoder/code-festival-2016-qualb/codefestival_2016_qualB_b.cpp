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
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    int x = 0, y = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'a') {
            if (x < a + b) {
                x++;
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else if (s[i] == 'b') {
            if (x < a + b && y < b) {
                cout << "Yes" << endl;
                x++;
                y++;
            } else {
                cout << "No" << endl;
            }
        } else {
            cout << "No" << endl;
        }
    }
}