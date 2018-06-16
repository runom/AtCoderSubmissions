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
	int a, b;
	cin >> a >> b;
	
	int ans = 0;
	
	while(a <= b) {
		if(a % 400 == 0) {
			ans++;
			a++;
			break;
		}
		
		if(a % 4 == 0 && a % 100 != 0) {
			ans++;
		}
		a++;
	}
	
	int c = 0;
	for(int i = 0; i < 400; ++i) {
		if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0){
			c++;
		}
	}
	int t = b - a;
	
	ans += c * (t / 400);
	
	a += (t / 400) * 400;
	
	while(a <= b) {
		if((a % 4 == 0 && a % 100 != 0) || a % 400 == 0){
			ans++;
		}
		a++;
	}
	
	cout << ans << endl;
}