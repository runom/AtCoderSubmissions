#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<int> S;
int N;
int a[100001];
int ans;

int main() {
	int s = 0;
	cin >> N;
	
	for(int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	
	for(int i = 0; i < N; ++i) {
		while(S.count(a[i])){
			S.erase(a[s++]);
		}
		S.insert(a[i]);
		ans = max(ans, (int)S.size());
	}
	
	cout << ans << endl;
	
	return 0;
}