#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <functional>
#include <cassert>
using namespace std;

typedef pair<int, int> P;

int main() {
	
	int n, t;
	cin >> n >> t;
	vector<P> c(n);
	int a_sum = 0, b_sum = 0;
	for(int i = 0; i < n; ++i) {
		cin >> c[i].first >> c[i].second;
		a_sum += c[i].first;
		b_sum += c[i].second;
	}
	
	if(a_sum <= t) {
		cout << 0 << endl;
		return 0;
	} else if(b_sum > t) {
		cout << -1 << endl;
		return 0;
	}
	
	sort(c.begin(), c.end(), [](P a, P b){return (a.first - a.second) > (b.first - b.second);});
	int cnt = 0;
	for(int i = 0; i < n && a_sum > t; ++i) {
		a_sum -=c[i].first;
		a_sum +=c[i].second;
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}