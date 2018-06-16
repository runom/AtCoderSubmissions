#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int cnt = 0;
	for(int i = 0; i < 12; ++i) {
		string s;
		cin >> s;
		if(count(s.begin(), s.end(), 'r')) cnt++;
	}
	cout << cnt << endl;
	return 0;
}