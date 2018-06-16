#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	
	int ans = 0;
	int prev = -1;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		
		if(prev != -1) {
			if(a - prev > t) {
				ans += t;
			} else {
				ans += a - prev; 
			}
		}
		
		prev = a;
	}
	
	ans += t;
	
	cout << ans << endl;
	return 0;
}