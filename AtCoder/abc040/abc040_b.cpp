#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n;
	
	cin >> n;
	
	int ans = 1 << 28;
	
	for(int w = 1; w <= n; ++w) {
		int h = n / w;
		int r = n % w;
		
		ans = min(ans, abs(w - h) + r);
	}
	
	cout << ans << endl;
	
	return 0;
}