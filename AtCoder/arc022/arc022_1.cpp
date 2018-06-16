#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	int i = 0;
	for(; !(s[i] == 'I' || s[i] == 'i') && i < s.size(); ++i);
	for(; !(s[i] == 'C' || s[i] == 'c') && i < s.size(); ++i);
	for(; !(s[i] == 'T' || s[i] == 't') && i < s.size(); ++i);
	
	cout << (i != s.size() ? "YES" : "NO") << endl;
	
	return 0;
}