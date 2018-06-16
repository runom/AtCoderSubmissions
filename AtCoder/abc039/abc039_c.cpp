#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	
	string key = "WBWBWWBWBWBW";
	key += key;
	key += key;
	
	string s;
	cin >> s;

	int ans = key.find(s);
	
	if(ans == 0) {
		cout << "Do" << endl;
	} else if(ans == 2) {
		cout << "Re" << endl;
	} else if(ans == 4) {
		cout << "Mi" << endl;
	} else if(ans == 5) {
		cout << "Fa" << endl;
	} else if(ans == 7) {
		cout << "So" << endl;
	} else if(ans == 9) {
		cout << "La" << endl;
	} else if(ans == 11) {
		cout << "Si" << endl;
	} else {
		return -1;
	}
	
	return 0;
}