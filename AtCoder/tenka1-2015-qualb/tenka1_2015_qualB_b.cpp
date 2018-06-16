#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	
	int cnt = 0;
	
	if(s == "{}") {
		cout << "dict" << endl;
		return 0;
	}
	
	for(int i = 0; i < (int)s.length(); ++i) {
		if(s[i] == '{') {
			cnt++;
		}
		else if(s[i] == '}') {
			cnt--;
		}
		else if(s[i] == ':' && cnt == 1) {
			cout << "dict" << endl;
			return 0;
		}
		else if(s[i] == ',' && cnt == 1) {
			cout << "set" << endl;
			return 0;
		}
	}
	
	cout << "set" << endl;
	return 0;
}