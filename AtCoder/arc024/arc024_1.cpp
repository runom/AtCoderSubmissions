#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	
	int L, R;
	cin >> L >> R;
	
	int ls[101] = {}, rs[101] = {};
	
	for(int i = 0; i < L; ++i) {
		int l;
		cin >> l;
		ls[l]++;
	}
	
	for(int i = 0; i < R; ++i) {
		int r;
		cin >> r;
		rs[r]++;
	}
	
	int ans = 0;
	
	for(int i = 1; i <= 100; ++i) {
		ans += min(ls[i], rs[i]);
	}
	
	cout << ans << endl;
	
	return 0;
}