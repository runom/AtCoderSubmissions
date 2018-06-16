#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	vector<int> w(m + 1);
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
		w[v[i]]++;
	}
	
	for(int i = 0; i <= m; ++i) {
		if(w[i] * 2 > n ) {
			cout << i << endl;
			return 0;
		}
	}
	cout << '?' << endl;
	
	return 0;
}