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
	int b;
	cin >> s >> b;
	b %= s.size();
	if(b == 0) {
		cout << s.back() << endl;
	} else {
		cout << s[b - 1] << endl;
	}
}