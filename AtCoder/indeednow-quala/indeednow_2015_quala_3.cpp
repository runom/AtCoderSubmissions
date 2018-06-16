#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> s(n);
	map<int, int> m;
	int zero_cnt = 0;
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
		if(s[i] == 0) {
			++zero_cnt;
		}
	}
	
	sort(s.rbegin(), s.rend());
	
	int prev = -1;
	for(int i = 0; i < n; ++i) {
		if(prev == s[i]) continue;
		m[i] = s[i] + 1;
	}
	
	
	n -= zero_cnt;
	
	
	int q;
	cin >> q;
	
	for(int i = 0; i < q; ++i) {
		int k;
		cin >> k;
		if(k >= n) {
			cout << 0 << endl;
		} else {
			auto it = m.lower_bound(k);
			cout << it->second << endl;
		}
	}
	return 0;
}