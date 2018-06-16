#include <iostream>
#include <set>
#include <cstdlib>
using namespace std;

const long long INF = 1LL << 60;

int main() {
	long long n, m;
	cin >> n >> m;
	
	set<long long> s;
	s.insert(INF);
	s.insert(-INF);
	
	s.insert(m);
	
	long long int ans = 0;
	
	for(int i = 0; i < n; ++i) {
		long long c;
		cin >> c;
		
		auto it = s.lower_bound(c);
		
		long long t = abs(c - *it);
		
		--it;
		
		t = min(t, abs(c - *it));
		
		++it; ++it;
		
		if(it != s.end())
			t = min(t, abs(c - *it));
		
		ans += t;
		
		s.insert(c);
	}
	
	cout << ans << endl;
	return 0;
}