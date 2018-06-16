#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> a;

int main() {
	cin >> n;
	a.resize(n);
	
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	int ans = -100000;
	
	for(int i = 0; i < n; ++i) {
		
		int t = -100000, s = 0;
		for(int j = 0; j < n; ++j) {
			if(i == j) continue;
			
			int l = min(i, j), r = max(i, j);
			
			int sum1 = 0, sum2 = 0;
			for(int k = l; k <= r; ++k) {
				if((k - l) % 2 == 0) {
					sum1 += a[k];
				} else {
					sum2 += a[k];
				}
			}
			
			if(sum2 > t) {
				t = sum2;
				s = sum1;
			}
		}
		
		ans = max(ans, s);
	}
	
	cout << ans << endl;
	return 0;
}