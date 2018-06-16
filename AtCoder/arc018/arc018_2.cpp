#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;

long long int x[101], y[101];
pair<int, int> p[101];

int main() {
	
	int N, ans = 0;
	
	cin >> N;
	
	for(int i = 0; i < N; ++i) {
		cin >> p[i].first >> p[i].second;
		//cin >> x[i] >>  y[i];
	}
	
	sort(p, p + N);
	
	for(int i = 0; i < N; ++i) {
		x[i] = p[i].first;
		y[i] = p[i].second;
	}
	
	for(int i = 0; i < N; ++i) {
		for(int j = i + 1; j < N; ++j) {
			for(int k = j + 1; k < N; ++k) {
				
				if(x[i] == x[j] && x[j] == x[k]) continue;
				if(y[i] == y[j] && y[j] == y[k]) continue;
				
				if(y[j] != y[i] && y[k] - y[i] != 0 && abs((double)(x[j] - x[i])/(y[j] - y[i]) - (double)(x[k] - x[i])/(y[k] - y[i])) < 1e-8) continue;
				
				long long int a = x[j] - x[i], b = y[j] - y[i], c = x[k] - x[i], d = y[k] - y[i];
				
				if((a * d - b * c) % 2 == 0) ans++;
				
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}