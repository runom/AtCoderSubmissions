#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	string s;
	cin >> s;
	int n;
	cin >> n;
	cout << s[(n-1)/ 5] << s[(n-1)%5] << endl;
	
	return 0;
}