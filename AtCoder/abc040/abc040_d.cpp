#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

struct edge
{
	int from, to, year;
};

struct query
{
	int v, w, i;
};

int n, m;
vector<edge> edges;

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < m; ++i) {
		int a, b, y;
		cin >> a >> b >> y;
		edges.push_back((edge){a - 1, b - 1, y});
	}
	
	sort(edges.begin(), edges.end(), [](const edge& a, const edge& b){return a.year > b.year;});
	
	int q;
	cin >> q;
	
	vector<query> queries;
	
	for(int i = 0; i < q; ++i) {
		int v, w;
		cin >> v >> w;
		queries.push_back((query){v - 1, w, i});
	}
	
	sort(queries.begin(), queries.end(), [](const query& a, const query& b){return a.w > b.w;});
	
	UnionFind uf(n);
	
	int query_index = 0;
	
	vector<int> ans(q);
	for(edge& e : edges) {
		while(query_index < queries.size() && e.year <= queries[query_index].w) {
			ans[queries[query_index].i] = uf.size(queries[query_index].v);
			query_index++;
		}
		uf.unionSet(e.from, e.to);
	}
	
	while(query_index < queries.size()) {
		ans[queries[query_index].i] = uf.size(queries[query_index].v);
		query_index++;
	}
	
	for(int i = 0; i < q; ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}