#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const long long MOD = 1000000007; 

long long fact_mod(int n)
{
	long long res = 1;
	for(int i = 1; i <= n; ++i) {
		res = res * i % MOD;
	}	
	return res;
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	
	long long sum = 0;
	for(int i = 0; i < n; ++i) {
		sum += v[i] * (n - i);
	}
	cout << sum << endl;

	map<int, int> m;
		
	for(int t : v){
		++m[t];
	}
	long long comb = 1;
	
	for(auto& x : m) {
		comb = comb * fact_mod(x.second) % MOD;
	}
	
	cout << comb << endl;
	return 0;
}