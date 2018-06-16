#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int64_t> a(7);
	
	for(int i = 0; i < 7; ++i) {
		cin >> a[i];
	}
	
	int I = a[0], J = a[3], L = a[4];
	
	int64_t ans = a[1];
	
	if(I > 2) {
		ans += (I - 2) / 2 * 2;
		I = 2 + (I - 2) % 2;
	}
	
	if(J > 2) {
		ans += (J - 2) / 2 * 2;
		J = 2 + (J - 2) % 2;
	}
	
	if(L > 2) {
		ans += (L - 2) / 2 * 2;
		L = 2 + (L - 2) % 2;
	}
	
	int maxi = 0;
	for(int I1 = 0; I1 <= I; ++I1) {
		int I2 = I - I1;
		
		int x = min({I1, L, J});
		
		maxi = max(maxi, 3 * x + I2 / 2 * 2 + (L - x) / 2 * 2 + (J - x) / 2 * 2);
	}
	
	cout << ans + maxi << endl;
	
	return 0;
}