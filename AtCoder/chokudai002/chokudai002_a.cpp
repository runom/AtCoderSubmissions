#include <iostream>
#include <vector>
using namespace std;
 
int a[1000000];
 
 
vector<int> divisor(int n) {
	vector<int> res;
	for(int i = 1; i * i <= n; ++i) {
		if(n % i == 0) {
			res.push_back(i);
			if(i != n / i) res.push_back(n / i);
		}
	}
	
	return res;
}

int main() {
	
	a[0] = a[1] = 1;
	
	int cnt = 0;
	for(int i = 2; i * i < 1000000; ++i) {
		if(a[i] == 0) {
			cnt++;
			for(int j = i * i; j < 1000000; j += i) {
				a[j] = 1;
			}
		}
	}
	
	vector<int> primes;
	primes.reserve(cnt);
	for(int i = 0; i < 1000000; ++i) {
		if(a[i] == 0) {
			primes.push_back(i);
		}
	}
	
	for(int j = 0; j < 100; ++j) {
		int n = 2162160;
		if(n < 1000000000 / primes[j + 6]) {
			n *= primes[j + 6];
		}
		
		while(true) {
				int k = rand() % 3;
				if(n < 1000000000 / primes[k]) {
					n *= primes[k];
				}
				
				if(n > 1000000000 / 2) {
					break;
				}
			}
		cout << n << endl;
	}
	
	return 0;
}