#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	long long N, K;
	cin >> N >> K;
	
	cout << setprecision(12) << (long double)(3*(2*(K-1)*(N-K)+(N-1)) + 1) / (N * N * N) << endl;
	
	return 0;
}