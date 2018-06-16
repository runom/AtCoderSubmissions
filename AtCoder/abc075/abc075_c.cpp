#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

bool check(vector<vector<int>> a) {
	int n = a.size();
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(i != j && a[i][j] == 0) {
				a[i][j] = 1 << 29;
			}
		}
	}
	
	for(int k = 0; k < n; ++k) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}	
	}
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(a[i][j] == (1 << 29)) {
				return true;
			}
		}
	}
	
	return false;
}

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> a(n, vector<int>(n));
	
	for(int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		
		a[x][y] = a[y][x] = 1;
	}
	
	int ans = 0;
	
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			if(!a[i][j]) {
				continue;
			}
			
			a[i][j] = 0;
			
			if(check(a)) {
				ans++;
			}
			
			a[i][j] = 1;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}