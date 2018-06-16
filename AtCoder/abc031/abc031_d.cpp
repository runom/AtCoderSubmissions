#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iterator>
using namespace std;

int k, n;
vector<string> v, w;

vector<int> lengths;


void check()
{
	map<char, string> strs;
	for(int i = 0; i < n; ++i) {
		string s;
		for(int j = 0; j < v[i].size(); ++j) {
			if(!strs.count(v[i][j])) {
				if(s.size() + lengths[v[i][j] - '1'] > w[i].size()) return;
				strs[v[i][j]] = w[i].substr(s.size(), lengths[v[i][j] - '1']);	
			} 
			s += strs[v[i][j]];
		}
		if(s != w[i]) {
			return;
		}
	}
	
	for(auto& x : strs) {
		cout << x.second << endl;
	}
	exit(0);	
}

void dfs(int k) {
	if(k == ::k) {
		check();
		return;
	}
	
	
	for(int i = 1; i <= 3; ++i) {
		lengths[k] = i;
		dfs(k + 1);
	}
}

int main() {
	cin >> k >> n;
	v.resize(n);
	w.resize(n);
	
	for(int i = 0; i < n; ++i) {
		cin >> v[i] >> w[i];
	}
	
	lengths.resize(k, -1);
	
	dfs(0);
	
	return 0;
}