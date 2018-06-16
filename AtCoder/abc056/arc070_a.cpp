#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int x;
	cin >> x;
	
	cout << (int)ceil((-1 + sqrt(1 + 8.0 * x)) / 2.0) << endl;
	return 0;
}