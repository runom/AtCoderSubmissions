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

int a1[26], a2[26], a3[26];

int main()
{
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	for(int i = 0; i < (int)s1.size(); ++i) {
		a1[s1[i] - 'A']++;
		a2[s2[i] - 'A']++;
		a3[s3[i] - 'A']++;
	}
	int b1 = 0, b2 = 0;
	int t1 = 0, t2 = 0;
	for(int i = 0; i < 26; ++i) {
		//cout << (char)('A' + i) << endl; 
		if(a3[i] == 0) continue;
		else if(a1[i] + a2[i] < a3[i]) {
			cout << "NO" << endl;
			return 0;
		} else if(a1[i] + a2[i] == a3[i]) {
			b1 += a1[i];
			b2 += a2[i];
		} else if(a1[i] >= a3[i] && a2[i] == 0){
			b1 += a3[i];
		} else if(a2[i] >= a3[i] && a1[i] == 0) {
			b2 += a3[i];
		} else {
			int ma = a1[i] > a3[i] ? a3[i] : a1[i];
			int mi = a3[i] - a2[i] <= 0 ? 0 : a3[i] - a2[i];
			//cout << ma << ' ' << mi << endl;
			t1 += ma;
			t2 += mi;
		}
	}
	
	int n = (int)s1.size();
	/*
	cout << b1 << ' ' << b2 << endl;
	cout << t1 << ' ' << t2 << endl;
	
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	sort(s3.begin(), s3.end());
	
	cout << s1 << endl << s2 << endl << s3 << endl;
	*/
	if(b1 + t2 <= n / 2 && n / 2 <= b1 + t1) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	
}