#include <iostream>

using namespace std;

int main() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];

    sort(a, a + 3);

    int ans = 1 << 26;

    for (int i = a[0]; i <= a[2]; i++) {
        int cnt = 0;

        for (int j = 0; j < 3; j++) {
            if (i > a[j]) {
                if ((i - a[j]) % 2 == 0) {
                    cnt += (i - a[j]) / 2;
                } else {
                    cnt = 1 << 26;
                    break;
                }
            } else {
                cnt += a[j] - i;
            }
        }

        ans = min(ans, cnt);
    }

    cout << ans << endl;
}