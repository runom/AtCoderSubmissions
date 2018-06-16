#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	
	string s;
	cin >> s;
	
	int t;
	cin >> t;
	
	int x = 0, y = 0;
	int q = 0;
	for(int i = 0; i < (int)s.size(); ++i) {
		switch(s[i]) {
			case 'L':
				--x;
				break;
			case 'R':
				++x;
				break;
			case 'U':
				++y;
				break;
			case 'D':
				--y;
				break;
			case '?':
				++q;
				break;
		}
	}
	
	int ans;
	
	if(t == 1) {
		ans = abs(x) + abs(y) + q;
	} else {
		ans = abs(x) + abs(y) - q;
		if(ans < 0) {
			ans = (-ans) % 2;
		}
	}
	
	cout << ans << endl;
	return 0;
}