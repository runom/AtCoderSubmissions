#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int INF = 1 << 26;

using P = pair<int, int>;

int dx[] = {1, -1, 0, 0,}, dy[] = {0, 0, 1, -1};

bool range_check(int x, int y, int w, int h) {
	return (0 <= x && x < w && 0 <= y && y < h);
}

int main() {
	
	int h, w;
	cin >> h >> w;
	
	vector<string> maze(h);

	int sx, sy, gx, gy;
	for(int i = 0; i < h; ++i) {
		cin >> maze[i];
		for(int j = 0; j < w; ++j) {
			if(maze[i][j] == 'S') {
				sx = j;
				sy = i;
			} 
			
			if(maze[i][j] == 'G') {
				gx = j;
				gy = i;
			}
		}
	}
	
	vector<vector<int>> d1(h, vector<int>(w, INF));
	vector<vector<int>> d2 = d1;
	
	queue<P> que;
	d1[sy][sx] = 0;
	que.emplace(sx, sy);
	
	while(!que.empty()) {
		P p = que.front(); que.pop();
		
		for(int k = 0; k < 4; ++k) {
			int nx = p.first + dx[k], ny = p.second + dy[k];
			
			if(range_check(nx, ny, w, h) && maze[ny][nx] != '#' && d1[ny][nx] == INF) {
				d1[ny][nx] = d1[p.second][p.first] + 1;
				que.emplace(nx, ny);
			}
		}
	}
	
	d2[gy][gx] = 0;
	que.emplace(gx, gy);
	
	while(!que.empty()) {
		P p = que.front(); que.pop();
		
		for(int k = 0; k < 4; ++k) {
			int nx = p.first + dx[k], ny = p.second + dy[k];
			
			if(range_check(nx, ny, w, h)  && maze[ny][nx] != '#' && d2[ny][nx] == INF) {
				d2[ny][nx] = d2[p.second][p.first] + 1;
				que.emplace(nx, ny);
			}
		}
	}
	
	int ans = 0;
	
	for(int i = 0; i < h; ++i) {
		for(int j = 0; j < w; ++j) {
			if(maze[i][j] == '#') {
				int d1min = INF, d2min = INF;
				for(int k = 0; k < 4; ++k) {
					int nx = j + dx[k], ny = i + dy[k];
					
					if(range_check(nx, ny, w, h) && d1[ny][nx] != INF && d1[ny][nx] < d1min){
						d1min = d1[ny][nx];
					}
					
					if(range_check(nx, ny, w, h) && d2[ny][nx] != INF && d2[ny][nx] < d2min){
						d2min = d2[ny][nx];
					}
				}
				
				
				//cout << j << ' ' << i << ' ' << d1min << ' ' << d2min << endl;  
				if(d1min != INF && d2min != INF) {
					ans = max(ans, d1min + d2min + 2);
				}
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}