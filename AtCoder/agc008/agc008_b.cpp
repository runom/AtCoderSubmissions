#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int64_t n, k;
	cin >> n >> k;

	vector<int64_t> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	vector<int64_t> pos_cumsum(n + 1), neg_cumsum(n + 1);
	
	for(int i = 0; i < n; ++i) {
		if(a[i] > 0) {
			pos_cumsum[i + 1] = pos_cumsum[i] + a[i];
			neg_cumsum[i + 1] = neg_cumsum[i];
		} else {
			pos_cumsum[i + 1] = pos_cumsum[i];
			neg_cumsum[i + 1] = neg_cumsum[i] + a[i];
		}
	}

	
	int64_t ans = 0;
	for(int i = k; i <= n; ++i) {
		int64_t l = pos_cumsum[i - k];
		int64_t m = pos_cumsum[i] - pos_cumsum[i - k] + neg_cumsum[i] - neg_cumsum[i - k];
		int64_t r = pos_cumsum[n] - pos_cumsum[i];
		
		ans = max(ans, l + r + max(int64_t(0), m));
	}
	
	cout << ans << endl;
	
	return 0;
}