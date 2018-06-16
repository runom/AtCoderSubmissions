#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	double a = 30.0 * (n % 12) + 30.0 * m / 60.0;
	double b = 360.0 * m / 60.0;
	
	auto c = max(a, b) - min(a, b);
	
	cout << fixed << (c > 180.0 ? 360.0 - c : c) << endl;
	
	return 0;
}