#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	for(char c : s) {
		if('0' <= c && c <= '9') {
			cout << c;
		}
	}
	cout << endl;
	return 0;
}