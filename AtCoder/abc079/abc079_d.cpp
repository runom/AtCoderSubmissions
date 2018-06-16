#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    int d[10][10];

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> d[i][j];
        }
    }

    for(int k = 0; k < 10; k++) {
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            int a;
            cin >> a;

            if(a != -1) {
                ans += d[a][1];
            }
        }
    }

    cout << ans << endl;
}