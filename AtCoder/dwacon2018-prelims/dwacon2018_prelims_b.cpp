#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();

    vector<int> a(n + 1);

    int ans = 0;

    for(int i = 0; i < n; i++) {
        a[i + 1] = a[i] + (s[i] == '2' ? 1 : -1);

        if(a[i + 1] < 0) {
            cout << -1 << endl;
            return 0;
        }

        ans = max(ans, a[i + 1]);
    }

    if(a[n] != 0) {
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;
}