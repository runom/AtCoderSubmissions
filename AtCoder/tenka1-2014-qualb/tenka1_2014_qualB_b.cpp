#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <cstdlib>
#include <cassert>
using namespace std;


int n;
string s;
vector<string> v;

long long memo[1001];

long long f(int i)
{
	if(i == s.size()) return 1;
	
	if(memo[i] != -1) return memo[i];
	
	long long res = 0;
	
	for(int j = 0; j < (int)v.size(); ++j) {
		bool ok = true;
		for(int k = 0; k < (int)v[j].size(); ++k) {
			if(i + k >= s.size() ||  s[i + k] != v[j][k]) {
				ok = false;
				break;
			}
		}
		
		if(ok) {
			res += f(i + v[j].size()) % 1000000007;
		}
	}
	
	return memo[i] = res % 1000000007;
}

int main() {
	cin >> n;
	cin >> s;
	
	v.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	
	sort(begin(v), end(v));
	fill(begin(memo), end(memo), -1);
	cout << f(0) << endl;
	
}
