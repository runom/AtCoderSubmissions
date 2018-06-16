#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iomanip>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> ls(2 * n);
	for(auto& l : ls) {
		cin >> l;
	}

	sort(ls.begin(), ls.end());

	int ans = 0;
	for(int i = 0; i < n; ++i) {
		ans += ls[2 * i];
	}	

	cout << ans << endl;
}