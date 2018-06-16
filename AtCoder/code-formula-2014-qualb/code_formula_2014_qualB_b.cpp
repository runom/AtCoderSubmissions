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
	string s;
	cin >> s;
	
	int a = 0, b = 0;
	
	int n = s.size();
	
	for(int i = 0; i < n; ++i) {
		if(i&1) {
			a += s[n - i - 1] - '0';
		} else {
			b += s[n - i - 1] - '0';
		}
	}
	
	cout << a << ' ' << b << endl;
	
}