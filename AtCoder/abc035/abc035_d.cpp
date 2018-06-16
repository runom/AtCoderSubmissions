#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
using namespace std;

using ll = long long;
const ll INF = 1LL << 61;

struct Edge{
	ll to;
	ll cost;
};

int main() {
	ios_base::sync_with_stdio(false);
	
	ll n, m, t;
	cin >> n >> m >> t;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	vector<vector<Edge>> E1(n);
	vector<vector<Edge>> E2(n);
	for(int i = 0; i < m; ++i) {
		ll from, to, cost;
		cin >> from >> to >> cost;
		E1[from-1].push_back(Edge{to-1, cost});
		E2[to-1].push_back(Edge{from-1, cost});
	}
	
	using P = pair<ll, ll>;
	
	priority_queue<P, vector<P>, greater<P>> que1;
	vector<ll> d1(n);
	fill(d1.begin(), d1.end(), INF);
	d1[0] = 0;
	
	que1.push(P(0, 0));
	
	while(!que1.empty()) {
		P p = que1.top(); que1.pop();
		ll v = p.second;
		if(d1[v] < p.first) continue;
		for(int i = 0; i < E1[v].size(); ++i) {
			Edge e = E1[v][i];
			if(d1[e.to] > d1[v] + e.cost) {
				d1[e.to] = d1[v] + e.cost;
				que1.push(P(d1[e.to], e.to));
			}
		}
	}
	
	/*for(int i = 0; i < n; ++i) {
		if(d1[i] != INF) {
			cout << d1[i] << endl;
		} else {
			cout << "inf" << endl;
		}
	}*/
	
	priority_queue<P, vector<P>, greater<P>> que2;
	vector<ll> d2(n);
	fill(d2.begin(), d2.end(), INF);
	d2[0] = 0;
	
	que2.push(P(0, 0));
	
	while(!que2.empty()) {
		P p = que2.top(); que2.pop();
		ll v = p.second;
		if(d2[v] < p.first) continue;
		for(int i = 0; i < E2[v].size(); ++i) {
			Edge e = E2[v][i];
			if(d2[e.to] > d2[v] + e.cost) {
				d2[e.to] = d2[v] + e.cost;
				que2.push(P(d2[e.to], e.to));
			}
		}
	}
	
	/*for(int i = 0; i < n; ++i) {
		if(d2[i] != INF) {
			cout << d2[i] << endl;
		} else {
			cout << "inf" << endl;
		}
	}*/
	
	ll ans = -1;
	
	for(int i = 0; i < n; ++i) {
		if(d1[i] + d2[i] >= t) continue;
		
		ans = max(ans, static_cast<ll>(a[i]) * (t - d1[i] - d2[i]));
	}
	
	cout << ans << endl;
	return 0;
}