#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <utility>
using namespace std;


int n;
string s;

string lcs(const string& a, const string& b) {
    const int n = a.size(), m = b.size();
    vector< vector<int> > X(n+1, vector<int>(m+1));
    vector< vector<int> > Y(n+1, vector<int>(m+1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i] == b[j]) {
                X[i+1][j+1] = X[i][j] + 1;
                Y[i+1][j+1] = 0;
            } else if (X[i+1][j] < X[i][j+1]) {
                X[i+1][j+1] = X[i][j+1];
                Y[i+1][j+1] = +1;
            } else {
                X[i+1][j+1] = X[i+1][j];
                Y[i+1][j+1] = -1;
            }
        }
    }
    string c;
    for (int i = n, j = m; i > 0 && j > 0; ) {
        if      (Y[i][j] > 0) --i;
        else if (Y[i][j] < 0) --j;
        else { c.push_back(a[i-1]); --i; --j; }
    }
    reverse(c.begin(), c.end());
    return c;
}

int main()
{
    cin >> n >> s;
    
    string t, u;
    for(int i = 1; i < n; ++i) {
        //cout << s.substr(0, i) << ' ' << s.substr(i) << endl;
        t = lcs(s.substr(0, i), s.substr(i));
        //cout << t << endl;
        if(u.size() < t.size()) {
            u = t;
        }
    }
    
    cout << n - u.size() * 2 << endl;
}
