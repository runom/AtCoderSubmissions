#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <functional>
#include <sstream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
	
	string s;
	cin >> s;
	int ans = 0;
	
	for(int i = 0; i < (int)s.size(); ++i) {
		ans += (i & 1 ? -1 : 1) * (s[i] - '0');
	}
		
	cout << ans << endl;
		
	
	return 0;
}