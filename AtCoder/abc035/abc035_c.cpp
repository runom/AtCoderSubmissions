#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	
	int n, q;
	cin >> n >> q;
	vector<int> w(n + 2);
	
	for(int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		
		++w[l];
		--w[r + 1];
	}
	
	int sum = 0;
	for(int i = 1; i <= n; ++i) {
		sum += w[i];
		cout << sum % 2;
	}
	cout << endl;
	
	return 0;
}