#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	
	int n = s.size();

	if(n == 26) {
		for(int i = n - 2; i >= 0; i--) {
			if(s[i] < s[i + 1]) {
				string substr = s.substr(0, i + 1);

				for(char c = s[i]; c <= 'z'; c++) {
					if(count(substr.begin(), substr.end(), c) == 0) {
						s[i] = c;
						break;
					}
				}

				cout << s.substr(0, i + 1) << endl;
				break;
			}
	
			if(i == 0) {
				cout << -1 << endl;
			}
		}
	} else {
		for(char c = 'a'; c <= 'z'; c++) {
			if(count(s.begin(), s.end(), c) == 0) {
				cout << s + c << endl;
				break;
			}
		}
	}
}
