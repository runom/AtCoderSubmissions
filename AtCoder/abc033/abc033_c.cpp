#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	int a = 1;
	vector<int> v;
	for(int i = 0; i < static_cast<int>(s.size()); ++i) {
		if(s[i] == '0') {
			a = 0;
		} else if(s[i] == '+') {
			v.push_back(a);
			a = 1;
		}
	}
	v.push_back(a);
	
	cout << v.size() - count(v.begin(), v.end(), 0) << endl;
	return 0;
}