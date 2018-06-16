#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> s(n);
	
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
		if(s[i] == 0) {
			cout << n << endl;
			return 0;
		}
	}
	
	int l = 0, r = 0;
	long long prod = 1;
	int ans = 0;
	while(r < n) {
		if(prod > k) {
			if(l < r) {
				prod /= s[l];
				l++;
			} else {
				cout << 0 << endl;
				return 0;
			}
		} else {
			ans = max(ans, r - l);
			prod *= s[r];
			r++;
		}
	}
	if(prod <= k) {
		ans = max(ans, r - l);
	}
	
	cout << ans << endl;
	return 0;
}