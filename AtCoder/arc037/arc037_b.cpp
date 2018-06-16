#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m;

vector<vector<int>> G;
vector<bool> visited;

bool dfs(int id, int prev)
{
	visited[id] = true;
	
	for(int to : G[id]) {
		if(prev != to) {
			if(visited[to]) return false;
			if(!dfs(to, id)) return false;
		}
	}
	
	return true;
}

int main() {
	cin >> n >> m;
	
	G.resize(n);
	
	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	visited.resize(n);
	
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		if(!visited[i]) {
			if(dfs(i, -1)) {
				++ans;
			}
		}
	}
	
	cout << ans << endl;
	return 0;
}