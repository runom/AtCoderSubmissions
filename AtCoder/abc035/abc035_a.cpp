#include <iostream>
using namespace std;

int main() {
	int w, h;
	cin >> w >> h;
	
	if(w * 3 == h * 4) {
		cout << "4:3" << endl;
	} else if(w * 9 == h * 16) {
		cout << "16:9" << endl;
	}
	return 0;
}