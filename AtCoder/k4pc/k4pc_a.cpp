#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int ans = 0;
	
	for(int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		if(a > i) {
			ans += a - i;
		}
	}
	
	cout << ans << endl;
	return 0;
}