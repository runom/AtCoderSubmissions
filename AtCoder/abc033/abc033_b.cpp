#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int sum = 0;
	int maxi = 0;
	string name;
	
	for(int i = 0; i < n; ++i) {
		string s;
		int p;
		cin >> s >> p;
		sum += p;
		if(p > maxi) {
			maxi = p;
			swap(name, s);
		}
	}
	
	if(2 * maxi > sum ) {
		cout << name << endl;
	} else {
		cout << "atcoder" << endl;
	}
	
	return 0;
}