#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m, t;
	cin >> n >> m >> t;
	
	vector<int> a(n);
	vector<int> b(t);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		
		for(int j = a[i] - m; j < a[i] + m; ++j) {
			if(0 <= j && j < t) {
				b[j] = 1;
			}
		}
	}
	
	int ans = 0;
	for(int i = 0; i < t; ++i) {
		if(b[i] == 0) {
			ans++;
		}
	}
	
	cout << ans << endl;
}