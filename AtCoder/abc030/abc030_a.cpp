#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	if(b * c > d * a) {
		cout << "TAKAHASHI" << endl;
	} else if(b * c < d * a) {
		cout << "AOKI" << endl;
	} else {
		cout << "DRAW" << endl;
	}
	
	return 0;
}