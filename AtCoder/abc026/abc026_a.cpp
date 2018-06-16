#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	
	int a;
	cin >> a;
	
	int maxi = 0;
	for(int x = 0; x <= a; ++x) {
		int y = a - x;
		maxi = max(maxi, x * y);
	}
	
	cout << maxi << endl;
	
	return 0;
}