#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	
	int x = 0;
	
	for(int i = 0; i < n; ++i) {
		string s;
		int d;
		cin >> s >> d;
		
		if(d < a) {
			d = a;
		} else if(d > b) {
			d = b;
		}
		
		if(s == "East") {
			x += d;
		} else {
			x -= d;
		}
	}
	
	if(x == 0) {
		cout << 0 << endl;
	} else if(x > 0) {
		cout << "East" << ' ' << x << endl;
	} else {
		cout << "West" << ' ' << -x << endl;
	}
	
	return 0;
}