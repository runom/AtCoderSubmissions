#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool check(int x, int a[])
{
    while(x > 0) {
        if(a[x % 10]) {
            return false;
        }
        x /= 10;
    }
    return true;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int a[10] = {0};
    for(int i = 0; i < k; ++i) {
        int tmp;
        cin >> tmp;
        a[tmp]++;
    }

    int ans = n;
    while(true) {
        if(check(ans, a)) {
            break;
        } else {
            ans++;
        }
    }

    cout << ans << endl;
}