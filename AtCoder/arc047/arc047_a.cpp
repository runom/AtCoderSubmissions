#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, l;
	string s;
	cin >> n >> l >> s;
	
	int c = 1, ans = 0;
	for(int i = 0; i < n; ++i) {
		if(s[i] == '+') {
			c++;
			if(c > l) {
				c = 1;
				ans++;
			}
		} else {
			c--;
		}
	}
	cout << ans << endl;
	return 0;
}