#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> ans;

    for (int i = 1; i <= 100; ++i) {
        int sum = 0;
        for (int j = 1; j <= i; ++j) {
            if (i % j == 0) {
                sum += j;
            }
        }

        if (sum == 98) {
            ans.push_back(i);
        }
    }

    for (int i = 0; i < ans.size(); ++i) {
        if (i != 0) {
            cout << ' ';
        }

        cout << ans[i];
    }

    cout << endl;
}