#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <cstdlib>
#include <cassert>
using namespace std;

int main() {
	string s;
	cin >> s;
	auto i = s.find("HAGIYA");
	s.replace(i, 6, "HAGIXILE");
	cout << s << endl;
}
