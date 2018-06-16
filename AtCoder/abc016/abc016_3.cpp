#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	int N, M;
	vector<int> graph[11];
	set<int> fri[11];
	cin >> N >> M;
	
	for(int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
		
		fri[a].insert(b);
		fri[b].insert(a);
	}
	
	vector<int> results(N);
	
	for(int i = 0; i < N; ++i) {
		set<int> ff;
		
		for(int x : graph[i]) {
			for(int y : graph[x]) {
				if(y != i && !fri[i].count(y)) {
					ff.insert(y);
				}
			}
		}
		
		cout << ff.size() << endl;
	}
	
	return 0;
}