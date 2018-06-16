#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	
	for(int i = 0; i < q; ++i) {
		int l, r, t;
		cin >> l >> r >> t;
		
		for(int i = l - 1; i <= r - 1; ++i) {
			a[i] = t;
		}
	}
	
	for(int i = 0; i < n; ++i) {
		cout << a[i] << endl;
	}
	return 0;
}