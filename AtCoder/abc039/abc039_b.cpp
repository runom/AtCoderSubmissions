#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int x;
	cin >> x;
	
	for(int i = 1; i < 1000; ++i) {
		if(i * i * i * i == x) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}