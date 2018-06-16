#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, X;
	int w[32];
	cin >> N >> X;
	
	for(int i = 0; i < N; ++i) {
		cin >> w[i];
	}
	
	int n1 = N / 2;
	int n2 = N - n1;
	
	vector<int> v;
	
	for(int i = 0; i < (1 << n1); ++i) {
		int x = 0;
		for(int j = 0; j < n1; ++j) {
			if(i & (1 << j)) {
				x += w[j];
			}
		}
		v.push_back(x);
	}
	
	sort(begin(v), end(v));
	
	auto ans = 0LL;
	
	for(int i = 0; i < (1 << n2); ++i) {
		int x = 0;
		for(int j = 0; j < n2; ++j) {
			if(i & (1 << j)) {
				x += w[n1 + j];
			}
		}
		
		auto range = equal_range(begin(v), end(v), X - x);
		ans += range.second - range.first;
	}
	
	cout << ans << endl;
	return 0;
}