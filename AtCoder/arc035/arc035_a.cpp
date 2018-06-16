#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	string t(s.rbegin(), s.rend());
	for(int i = 0; i < (int)s.size(); ++i) {
		if(!(s[i] == '*' || t[i] == '*' || s[i] == t[i])) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}