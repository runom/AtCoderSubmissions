#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
using namespace std;

int n;
vector<int> G[100001]; 
bool visited[100001];
vector<int> res;


int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	res.reserve(n);
	
	priority_queue<int, vector<int>, greater<int>> que;
	
	que.push(1);
	visited[1] = true;
	while(!que.empty()) {
		int id = que.top(); que.pop();
		res.push_back(id);
		
		for(int i = 0; i < G[id].size(); ++i) {
			if(!visited[G[id][i]]) {
				que.push(G[id][i]);
				visited[G[id][i]] = true;
			}
		}
		
	}
	
	for(int i = 0; i < (int)res.size(); ++i) {
		if(i!=0) cout << ' ';
		cout << res[i];
	} cout << endl;
	
}