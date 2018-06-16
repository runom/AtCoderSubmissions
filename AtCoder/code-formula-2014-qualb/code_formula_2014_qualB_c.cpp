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


string A, B;



bool check(string& s, int i)
{
	if(i == 3) return s == B;
	
	for(int k = 0; k < (int)s.size(); ++k){
		for(int m = 0; m < (int)s.size(); ++m) {
			if(k == m) continue;
			
			swap(s[k],s[m]);
			
			if(check(s, i + 1)) return true;
			
			swap(s[k], s[m]);
		}
	}	
	
	return false;
}

int main()
{
	cin >> A >> B;
	int d = 0;
	int cnt = 3;
	int n = A.size();
	
	for(int i = 0; i < n; ++i) {
		if(A[i] != B[i]) {
			d++;
		}
	}
	
	if(d > 6) {
		cout << "NO" << endl;
		return 0;
	}
	
	int index = 0;
	while(A.size() > 20 && index < A.size()) {
		if(A[index] == B[index]) {
			A.erase(A.begin() + index);
			B.erase(B.begin() + index);
		}
		else {
			index++;
		}
	}
	
	/*for(int i = 0; i < n && cnt > 0; ++i) {
		if(A[i] != B[i]) {
			for(int j = i + 1; j < n; ++j) {
				if(A[i] == B[j]) {
					swap(B[i], B[j]);
					--cnt;
				}
			}
		}
	}
	
	if(A != B) {
		cout << "NO" << endl;
	} else if(cnt == 0 || cnt == 2) {
		cout << "YES" << endl;
	} else {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(i == j) continue;
				if(B[i] == B[j]) {
					cout << "YES" << endl;
					return 0;
				}
			}
		}
		cout << "NO" << endl;
	}*/
	
	if(check(A, 0)) {
		cout << "YES" << endl;
	} else {
		cout <<"NO" << endl;
	}
	
}