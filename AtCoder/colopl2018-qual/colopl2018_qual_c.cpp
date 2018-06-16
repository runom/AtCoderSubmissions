#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
    if(b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

ll a, b;

ll dfs(ll i, vector<ll>& used) {
    if(i == b + 1) {
        return 1;
    }
    
    ll ret = dfs(i + 1, used);
    
    bool ok = true;
    for(ll u : used) {
        if(gcd(i, u) != 1) {
            ok = false;
            break;
        }
    }
    
    if(ok) {
        used.push_back(i);
        ret += dfs(i + 1, used);
        used.pop_back();
    }
    
    return ret;
}

int main() {
    cin >> a >> b;
    
    vector<ll> t;
    
    cout << dfs(a, t) << endl;
};