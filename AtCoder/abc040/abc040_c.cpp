#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
	int n;
	
	cin >> n;
	vector<int> a(n);
	
	for(int& x : a) {
		cin >> x;
	}
	
	const ll INF = 1LL << 60;
	vector<ll> dp(n, INF);
	
	dp[0] = 0;
	
	for(int i = 0; i < n; ++i) {
		if(i + 1 < n) {
			dp[i + 1] = min(dp[i + 1], dp[i] + abs(a[i] - a[i + 1]));
		}
		
		if(i + 2 < n) {
			dp[i + 2] = min(dp[i + 2], dp[i] + abs(a[i] - a[i + 2]));
		}
	}
	
	cout << dp[n - 1] << endl;
	return 0;
}