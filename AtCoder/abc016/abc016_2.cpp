#include <iostream>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	
	bool p = A + B == C, m = A - B == C;
	
	if(p && m) {
		cout << '?' << endl;
	} else if(!p && !m) {
		cout << '!' << endl;
	} else if(p) {
		cout << '+' << endl;
	} else if(m) {
		cout << '-' << endl;
	}
	
	return 0;
}