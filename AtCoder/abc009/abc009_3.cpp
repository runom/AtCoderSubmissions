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
    int n, k;
    cin >> n >> k;

    string s, t;
    cin >> s;
    t = s;

    vector<int> a(s.size());
    int b = 0;
    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        int d = -1;
        for (int j = i + 1; j < s.size(); ++j) {
            if (c > s[j]) {
                swap(s[i], s[j]);

                int e = 0;
                for (int i = 0; i < s.size(); ++i) {
                    e += s[i] != t[i];
                }

                swap(s[i], s[j]);

                if (e <= k) {
                    c = s[j];
                    d = j;
                }
            }
        }

        if (d != -1) {
            swap(s[i], s[d]);
        }
    }

    cout << s << endl;
}