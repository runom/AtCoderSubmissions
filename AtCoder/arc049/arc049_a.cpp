#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
using namespace std;

int main() {
	string s;
	int a, b, c, d;
	cin >> s >> a >> b >> c >> d;
	
	for(int i = 0; i < (int)s.size(); ++i) {
		if(i == a || i == b || i == c || i == d) {
			cout << '"';
		}
		cout << s[i];
	}
	
	if(d == s.size()) cout << '"';
	
	cout << endl;
}