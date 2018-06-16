#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

set<int> s;
vector<int> g[51];
	
void dfs(int i){
	s.insert(i);
	
	for(int x : g[i]) {
		dfs(x);
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	for(int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		g[b-1].push_back(a-1);
	}
	
	for(int x : g[0]) {
		dfs(x);
	}
	
	cout << s.size() + 1 << endl;
}