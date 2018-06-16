#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;

    int d[31][31];
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < c; j++) {
            cin >> d[i][j];
        }
    }

    int e[501][501];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> e[i][j];
        }
    }

    int cost[3][51];

    for(int m = 0; m <= 3; m++) {
        for(int col = 0; col < c; col++) {
            cost[m][col] = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if((i + j) % 3 != m) {
                        continue;
                    }

                    cost[m][col] += d[e[i][j]-1][col];
                }
            }
        }
    }

    int ans = 1 << 29;

    for(int i = 0; i < c; i++) {
        for(int j = 0; j < c; j++) {
            if(i == j) {
                continue;
            }
            for(int k = 0; k < c; k++) {
                if(i == k || j == k) {
                    continue;
                }

                ans = min(ans, cost[0][i] + cost[1][j] + cost[2][k]);
            }
        }
    }

    cout << ans << endl;
}