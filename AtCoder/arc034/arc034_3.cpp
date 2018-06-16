#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

using Int = long long;

void prime_factor(int n, map<int, Int>& res)
{
	for(int i = 2; i * i <= n; ++i) {
		while(n % i == 0) {
			res[i]++;
			n /= i;
		}
	}
	
	if(n != 1) res[n]++;
}

int main() {
	int a, b;
	cin >> a >> b;
	map<int, Int> cnt;
	
	for(int i = b + 1; i <= a; ++i) {
		prime_factor(i, cnt);
	}
	
	long long ans = 1;
	for(auto& p : cnt) {
		//cout << p.first << ' ' << p.second << endl;
		ans = (ans * (p.second + 1)) % 1000000007;
	}
	cout << ans << endl;
	return 0;
}