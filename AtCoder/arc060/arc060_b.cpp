#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

using ll = long long;

ll f(ll b, ll n) {
	if(b > n) {
		return n;
	} else {
		return f(b, n / b) + n % b;
	}
}

int main() {
	ll n, s;
	cin >> n >> s;
	
	ll i = 2;
	for(; i * i <= n; ++i) {
		if(f(i, n) == s) {
			cout << i << endl;
			return 0;
		}
	}
	
	ll a = n - s;
	
	if(a < 0) {
		cout << -1 << endl;
		return 0;
	} else if(a == 0) {
		cout << n + 1 << endl;
		return 0;
	}
	
	const ll inf = 1LL << 60;
	ll ans = inf;
	
	for(; i >= 1; --i) {
		if(a % i != 0) {
			continue;
		}
		
		ll b = a / i + 1;
		
		if(f(b, n) == s) {
			ans = min(ans, b);
		}
	}
	
	if(ans != inf) {
		cout << ans << endl; 
	} else {
		cout << -1 << endl;
	}
	
	return 0;
}