#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string target = "indeednow";
	sort(target.begin(), target.end());
	int n;
	cin >> n;
	
	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		cout << (s == target ? "YES" : "NO") << endl;
	}
	
	return 0;
}