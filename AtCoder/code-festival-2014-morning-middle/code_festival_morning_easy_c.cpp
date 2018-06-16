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
#include <cassert>
using namespace std;

const int INF = 1 << 26;

int n, m, s, t;
int ds[1005];
int dt[1005];
bool used[1005];
vector<vector<int>> table;

void dijkstra(int s, int d[]) {
	
	fill(d, d + n, INF);
	fill(used, used + n, false);
	d[s] = 0;
	
	while(true) {
		int v = -1;
		
		for(int u = 0; u < n; ++u) {
			if(!used[u] && (v == -1 || d[u] < d[v])) v = u;
		}
		
		if(v == -1) break;
		
		used[v] = true;
		
		for(int u = 0; u < n; ++u) {
			d[u] = min(d[u], d[v] + table[v][u]);
		}
	}
	
}

int main() {
	
	cin >> n >> m;
	cin >> s >> t;
	
	s--;
	t--;
	
	table = vector<vector<int>>(n, vector<int>(n, INF));
	
	for(int i = 0; i < m; ++i) {
		int x, y, d;
		cin >> x >> y >> d;
		x--;
		y--;
		table[x][y] = d;
		table[y][x] = d;
	}
	
	
	dijkstra(s, ds);
	dijkstra(t, dt);
	
	int anscost = INF;
	int ans;
	
	for(int i = 0; i < n; ++i) {
		if(ds[i] != INF && ds[i] == dt[i]) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;
	return 0;
}