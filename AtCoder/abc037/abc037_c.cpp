#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	long long sum = 0;
	long long ans = 0;
	int i;
	for(i = 0; i < k; ++i) {
		sum += a[i];
	}
	ans += sum;
	
	for(int j = 0; j < n - k; ++i, ++j) {
		sum -= a[i - k];
		sum += a[i];
		ans += sum;
	}
	
	cout << ans << endl;
	return 0;
}