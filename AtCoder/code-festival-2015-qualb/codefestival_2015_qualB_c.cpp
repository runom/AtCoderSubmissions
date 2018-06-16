#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	multiset<int> a;
	vector<int> b(m);
	
	for(int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		a.insert(tmp);
	}
	
	
	for(int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	
	for(int i = 0; i < m; ++i) {
		auto it = a.lower_bound(b[i]);
		if(it == a.end()) {
			cout << "NO" << endl;
			return 0;
		} else {
			a.erase(it);
		}
	}
	cout << "YES" << endl;
	return 0;
}