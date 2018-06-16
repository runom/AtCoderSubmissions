#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> x(n), y(n), c(n);
	
	for(int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i] >> c[i];
	}
	
	double maxi = 0.0;
	
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			if(abs(x[i] - x[j]) > abs(y[i] - y[j])) {
				maxi = max(maxi, (abs(x[i] - x[j]) / ((1.0 / c[i] + 1.0/c[j]))));
			} else {
				maxi = max(maxi, (abs(y[i] - y[j]) / ((1.0 / c[i] + 1.0/c[j]))));
			}
		}
	}
	
	cout << fixed << maxi << endl;
}