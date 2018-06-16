#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <functional>
using namespace std;

int main() {
	string s;
	cin >> s;
	s.pop_back();
	s += '5';
	cout << s << endl;
	return 0;
}