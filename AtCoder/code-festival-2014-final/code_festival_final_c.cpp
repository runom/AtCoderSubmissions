#include <iostream>
#include <limits>
using namespace std;

int main() {
	
	long long A;
	cin >> A;
	
	for(int i = 10; i < 20000; ++i) {
		string s = to_string(i);
		
		long long sum = 0;
		long long beki = 1;
		for(int j = s.size() - 1; j >= 0; --j) {
			sum += (s[j] - '0') * beki;
			beki *= i;
		}
		
		if(sum == A) {
			cout << i << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;
	
	return 0;
}