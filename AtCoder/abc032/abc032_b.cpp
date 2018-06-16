#include <iostream>
#include <set>
using namespace std;

int main() {
	
	string s;
	int k;
	cin >> s >> k;
	
	set<string> a;
	
	for(int i = 0; i < s.size(); i++) {
		if(i + k > s.size()) break;
		
		a.insert(s.substr(i, k));
	}
	
	cout << a.size() << endl;
	return 0;
}