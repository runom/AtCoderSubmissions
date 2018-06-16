#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int n, k;
vector<double> p, w;

bool check(double x) {
	vector<double> a(n);
	
	for(int i = 0; i < n; ++i) {
		a[i] = p[i] * w[i] - x * w[i];
	}
	
	sort(a.begin(), a.end(), greater<>());
	
	double s = 0.0;
	for(int i = 0; i < k; ++i) {
		s += a[i];
	}
	
	return s > 0.0;
}

int main() {
	cin >> n >> k;
	p.resize(n);
	w.resize(n);
	
	for(int i = 0; i < n; ++i) {
		cin >> w[i] >> p[i];
	}
	
	double left = 0.0, right = 100.0;
	double mid;
	for(int i = 0; i < 50; ++i) {
		mid = (left + right) / 2;
		if(check(mid)) {
			left = mid;
		} else {
			right = mid;
		}
	}
	
	cout << fixed << mid << endl;
	
	return 0;
}