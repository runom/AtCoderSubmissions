#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <iterator>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <cstdlib>
#include <cctype>
#include <numeric>
using namespace std;

int main()
{
	int n, target;
	cin >> n >> target;
	int sum = 0;
	int ans;
	bool f = false;
	for(int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		if(!f) {
			sum += t;
			if(sum >= target) {
				ans = i + 1;
				f = true;
			}
		}
	}
	
	cout << ans << endl;
}