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

int main()
{
    int n;
    string s;
    cin >> n >> s;
    
    if(n % 2) {
        cout << -1 << endl;
        return 0;
    }
    
    int ans = 0;
    for(int i = 0; i < n / 2; ++i) {
        if(s[i] != s[i + n / 2]) ans++;
    }
    cout << ans << endl;
}
