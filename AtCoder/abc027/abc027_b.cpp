#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	int sum = 0;
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
		sum += v[i];
	}
	
	if(sum % n != 0) {
		cout << -1 << endl;
		return 0;
	}
	
	int a = 0, b = 1;
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		a += v[i];
		if(a == sum * b / n) {
			a = 0;
			b = 1;
		} else {
			ans++;
			b++;
		}
	}
	
	cout << ans << endl;
	return 0;
}