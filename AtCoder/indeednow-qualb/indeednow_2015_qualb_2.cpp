#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	int cnt = 0;
	while(s != t && cnt < (int)s.size() + 3) {
		string u;
		u += s.back();
		for(int i = 0; i < (int)s.size() - 1; ++i) {
			u += s[i];
		}
		swap(u, s);
		++cnt;
	}
	
	if(s == t) {
		cout << cnt << endl;
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}