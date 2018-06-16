#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	vector<pair<int64_t, int64_t>> a(2 * n);
	
	for(int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		
		a[i * 2].first = a[i * 2 + 1].first = x;
		a[i * 2].second = a[i * 2 + 1].second = y;
	}
	
	vector<int> c(2 * n);
	c[0] = c[1] = c[2] = c[3] = 1;
	sort(c.begin(), c.end());
	
	int64_t ans = -1;
	
	do {
		int64_t t, b, l, r;
		bool f = false;
		
		for(int i = 0; i < 2 * n; ++i) {
			if(c[i]) {
				if(!f) {
					t = b = a[i].second;
					l = r = a[i].first;
					f = true;
				} else {
					t = min(t, a[i].second);
					b = max(b, a[i].second);
					l = min(l, a[i].first);
					r = max(r, a[i].first);
				}
			}
		}
		
		int cnt = 0;
		
		for(int i = 0; i < 2 * n; i += 2) {
			if(l <= a[i].first && a[i].first <= r && t <= a[i].second && a[i].second <= b) {
				cnt++;	
			}
		}
		
		if(cnt >= k) {
			if(ans == -1) {
				ans = (r - l) * (b - t);
			} else {
				ans = min(ans, (r - l) * (b - t));
			}
		}
		
	} while(next_permutation(c.begin(), c.end()));
	
	cout << ans << endl;
	
	return 0;
}