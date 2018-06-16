#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<string> v;
	for(int i = 1; i <= 1000; ++i) {
		v.push_back(to_string(i));
	}
	
	sort(v.begin(), v.end());
	
	for(auto& x : v) {
		cout << x << endl;
	}
	return 0;
}