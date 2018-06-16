#include <iostream>

using namespace std;

bool c[1000005];

int main() {
	int A;
	cin >> A;
	for(int i = 1; i * i * i < 1000005; ++i) {
		c[i * i * i] = true;
	}
	
	if(c[A]) {
		cout << "YES" << endl;
 	} else {
 		cout << "NO" << endl;
 	}
	return 0;
}