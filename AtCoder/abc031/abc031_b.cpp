#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int l, h, n;
	cin >> l >> h >> n;
	
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		
		if(l <= a && a <= h) {
			cout << 0 << endl;
		} else if(a > h) {
			cout << -1 << endl;
		} else {
			cout << l - a << endl;
		}
	}
	return 0;
}