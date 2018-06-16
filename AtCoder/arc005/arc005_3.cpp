#include <iostream>
#include <queue>
#include <utility>
using namespace std;
using Point = pair<int, int>;

Point sp, gp;
int H, W;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
bool a[3][501][501];
char c[501][501];

bool dfs(Point p, int k)
{
	if(p  == gp) return true;
	if(k > 2) return false;
	if(a[k][p.first][p.second]) return false;
	a[k][p.first][p.second] = true;
	
	//cout << p.first << ' ' << p.second << endl;
	//cout << k << endl;
	
	for(int i = 0; i < 4; ++i) {
		int ny = p.first + dy[i], nx = p.second + dx[i];
		if(0 <= nx && nx < W && 0 <= ny && ny < H) {
			if(dfs(Point(ny, nx), (c[ny][nx] == '#' ? k + 1 : k))) return true;
		} 
	}

	return false;
}

int main() {
	cin >> H >> W;
	for(int i = 0; i < H; ++i) {
		for(int j = 0; j < W; ++j) {
			cin >> c[i][j];
			if(c[i][j] == 's') {
				sp = Point(i, j);
			} else if(c[i][j] == 'g') {
				gp = Point(i, j);
			}
		}
	}
	
	if(dfs(sp, 0)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	
	return 0;
}