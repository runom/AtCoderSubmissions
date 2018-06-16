#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
using namespace std;
 
bool a[1000005];
 
struct S
{
	S(int k, int n, int id):k(k),n(n),id(id) {}
	int k, n, id;
	bool operator < (const S& other) const {
		return k == other.k ? n > other.n : k > other.k;
	}
};
 
int main() {
	int n, k;
	cin >> n >> k;
	priority_queue<S> que;
	
	vector<vector<int>> vn(n);
	
	int last = k;
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < k; ++j) {
			int c;
			cin >> c;
			que.emplace(j, i, c);
		}
		
		while(!que.empty() && last > 0){
			auto p = que.top(); que.pop();
			if(a[p.id]) continue;
			
			if((n - (i + 1)) * p.k < last) {
				vn[i].push_back(p.id);
				last--;
				a[p.id] = true;
			} else {
				que.push(p);
				break;
			}
		}
	}
	
	for(auto& v: vn) {
		sort(begin(v), end(v));
		for(int i = 0; i < (int)v.size(); ++i) {
			if(i != 0) cout << ' ';
			cout << v[i];
		}
		cout << endl;
	}
	
}
