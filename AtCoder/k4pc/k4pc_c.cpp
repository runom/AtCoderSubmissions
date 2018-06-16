#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <functional>
using namespace std;

const int INF = 1 << 28;

using P = pair<int, int>;

struct Node
{
	int weight;
	vector<int> child;
};

Node graph[100001];
int d[100001];
bool erased[100001];

void dfs(int pos, int w) {
	if(graph[pos].child.size() == 0) {
		d[pos] = w;
		return;
	}
	
	for(int child : graph[pos].child) {
		dfs(child, w + graph[child].weight);	
	}
}

void erase(int pos) {
	
	erased[pos] = true;
	
	if(graph[pos].child.size() == 0) {
		d[pos] = -1;
		return;
	}
	
	for(int child : graph[pos].child) {
		if(!erased[child]){
			erase(child);	
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int n, q;
	cin >> n >> q;
	
	fill(d, d + n, INF);
	
	for(int i = 1; i < n; ++i) {
		int p, w;
		cin >> p >> w;
		p--;
		graph[i].weight = w;
		graph[p].child.push_back(i);
	}
	
	dfs(0, 0);
	
	priority_queue<P, vector<P>, greater<P>> que;
	
	for(int i = 0; i < n; ++i) {
		if(d[i] != INF) {
			que.push(make_pair(d[i], i));
		}
	}
	
	for(int i = 0; i < q; ++i) {
		int x;
		cin >> x;
		erase(x-1);
		while(!que.empty()) {
			int p = que.top().second;
			if(d[p] == que.top().first) break;
			que.pop();
		}
		
		if(que.empty()) {
			cout << -1 << endl;
		} else {
			cout << que.top().first << endl;
		}
	}
	
	return 0;
}