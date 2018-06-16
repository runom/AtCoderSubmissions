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
    long long n, k, m, r;
    cin >> n >> k >> m >> r;
    vector<long long> s(n);
    
    for(long long i = 0; i < n - 1; ++i) {
        cin >> s[i];
    }
    
    sort(s.begin(), s.end(), greater<long long>());
    
    long long sum = 0;
    for(long long i = 0; i < k; ++i) {
        sum += s[i];
    }
    
    if(sum >= r * k) {
        cout << 0 << endl;
        return 0;
    }
    
    sum -= s[k-1];
    
    if(m >= r * k - sum) {
        cout << r * k - sum << endl;
    } else {
        cout << -1 << endl;
    }
}
