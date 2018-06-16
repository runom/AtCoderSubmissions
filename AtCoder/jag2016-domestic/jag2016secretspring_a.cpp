#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

using namespace std;

int main(void) {
	int c = 0;
	int n;

	int ans = 0;
	cin >> n;

	while( n-- ) {
		string s;
		cin >> s;

		if ( s == "A" ) {
			c++;
		}
		if ( s == "Un" ) {
			c--;
		}

		if ( c < 0 ) {
			ans = 1;
		}
	}

	if ( c != 0 || ans )
		cout << "NO" << endl;
	else
		cout << "YES" << endl;

	return 0;
}
