#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	auto f = [&](char c){return count(s.begin(), s.end(), c);};
	
	for(int i = 0; i < 6; ++i) {
		if(i != 0) cout << ' ';
		cout << f('A' + i);
	}
	cout << endl;
	
	return 0;
}