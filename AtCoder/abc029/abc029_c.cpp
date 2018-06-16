#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	int n;
	cin >> n;
	set<string> s;
	s.insert("a");
	s.insert("b");
	s.insert("c");
	
	for(int i = 1; i < n; ++i) {
		set<string> tmp;
		for(auto& t : s) {
			tmp.insert(t + 'a');
			tmp.insert(t + 'b');
			tmp.insert(t + 'c');
		}
		swap(s, tmp);
	}
	
	for(auto& t : s) {
		cout << t << endl;
	}

	return 0;
}