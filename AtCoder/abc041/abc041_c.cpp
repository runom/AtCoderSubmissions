#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;

const long long MOD = 1000'000'007;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; ++i) {
		cin >>v[i].first;
		v[i].second = i + 1;
	}
	
	sort(v.begin(), v.end(), greater<>());
	for(int i = 0; i < n; ++i) {
		cout << v[i].second << endl;
	}
	return 0;
}