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
#include <list>
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
    string x;
    cin >> x;

    stack<char> s;

    for (int i = 0; i < x.size(); ++i) {
        if (!s.empty() && s.top() == 'S' && x[i] == 'T') {
            s.pop();
        } else {
            s.push(x[i]);
        }
    }

    cout << s.size() << endl;
}