#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);

int main() {
	int n;
	cin >> n;
	vector<double> r(n);
	for(int i = 0; i < n; ++i) {
		cin >> r[i];
	}
	
	if(n % 2 == 1) r.push_back(0.0);
	
	sort(r.begin(), r.end(), greater<>());
	
	double ans = 0.0;
	
	for(int i = 0; i < n; i += 2) {
		ans += pi * r[i] * r[i] - pi * r[i+1] * r[i+1];
	}
	
	cout << fixed << ans << endl;
	
	return 0;
}