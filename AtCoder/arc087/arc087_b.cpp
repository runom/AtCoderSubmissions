#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <map>

using namespace std;

bool achievable(int x, const vector<int>& len) {
    int offset = accumulate(len.begin(), len.end(), 0);

    if(x > offset || x < -offset) {
        return false;
    }

    vector<vector<int>> dp(2, vector<int>(2 * offset + 1));

    dp[0][offset] = 1;

    for(int i = 0; i < len.size(); ++i) {
        fill(dp[!(i & 1)].begin(), dp[!(i & 1)].end(), 0);
        for(int j = 0; j < 2 * offset + 1; j++) {
            if(dp[i & 1][j]) {
                if(j - len[i] >= 0) {
                    dp[!(i & 1)][j - len[i]] = 1;
                }

                if(j + len[i] < 2 * offset + 1) {
                    dp[!(i & 1)][j + len[i]] = 1;
                }
            }
        }
    }

    return dp[len.size() & 1][x + offset];
}

int main() {
    string s;
    cin >> s;

    int x, y;
    cin >> x >> y;

    vector<int> a[2];

    int n = s.size();
    
    int i;
    for(i = 0; i < n; i++){
        if(s[i] == 'F') {
            x--;
        } else {
            break;
        }
    }

    int len = 0;
    int axis = 0;

    for(; i < n; i++) {
        if(s[i] == 'T') {
            if(len > 0) {
                a[axis].push_back(len);
            }

            len = 0;
            axis = !axis;
        } else {
            len++;
        }
    }

    if(len > 0) {
        a[axis].push_back(len);
    }

    if(achievable(x, a[0]) && achievable(y, a[1])) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}