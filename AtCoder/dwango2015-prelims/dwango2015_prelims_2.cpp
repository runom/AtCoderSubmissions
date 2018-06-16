#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	long long ans = 0;
	long long len = 0;
	char c = 0;
	
	for(int i = 0; i < (int)s.size(); ++i) {
		if(c == '2' && s[i] == '5') {
			len++;
		} else if(c == '5' && s[i] == '2') {
			
		} else {
			ans += len * (len + 1) / 2;
			len = 0;
		}
		c = s[i];
	}
	
	ans += len * (len + 1) / 2;
	
	cout << ans << endl;
	
	return 0;
}