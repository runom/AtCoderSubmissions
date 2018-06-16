#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
	vector<char> c(10, 'x');
	int a, b;
	cin >> a >> b;
	for(int i = 0; i < a; ++i) {
		int t;
		cin >> t;
		c[t] = '.';
	}
	
	for(int i = 0; i < b; ++i) {
		int t;
		cin >> t;
		c[t] = 'o';
	}
	
	cout << c[7] << ' ' << c[8] << ' ' << c[9] << ' ' << c[0] << endl;
	cout << ' ' << c[4] << ' ' << c[5] << ' ' << c[6] << endl;
	cout << ' ' << ' ' << c[2] << ' ' << c[3] << endl;
	cout << ' ' << ' ' << ' ' << c[1] << endl;
	
	
}