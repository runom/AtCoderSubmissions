#include <iostream>
#include <string>
using namespace std;

const long long MOD = 1000'000'007;

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	cout << (a * b % MOD) * c % MOD << endl;
	return 0;
}