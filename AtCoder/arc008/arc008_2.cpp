#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	string name, kit;
	
	cin >> name >> kit;
	
	int cnt1[26] = {}, cnt2[26] = {};
	
	for(char c : name) {
		cnt1[c - 'A']++;
	}
	
	for(char c : kit) {
		cnt2[c - 'A']++;
	}
	
	int ans = 0;
	for(int i = 0; i < 26; ++i) {
		if(cnt1[i] == 0) continue;
		
		if(cnt1[i] > 0 && cnt2[i] == 0) {
			cout << -1 << endl;
			return 0;
		}
		int t = cnt1[i] / cnt2[i];
		if(cnt1[i] == cnt2[i] * t) {
			ans = max(ans, t);
		} else {
			ans = max(ans, t + 1);
		}
	}
	cout << ans << endl;
	return 0;
}