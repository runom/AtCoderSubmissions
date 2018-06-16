#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	
	vector<string> pic(h);
	for(int i = 0; i < h; ++i) {
		cin >> pic[i];
	}
	
	auto ans = pic;
	
	for(int i = 0; i < h; ++i) {
		for(int j = 0; j < w; ++j) {
			if(pic[i][j] == '.') {
				for(int dx = -1; dx <= 1; ++dx) {
					for(int dy = -1; dy <= 1; ++dy) {
						int x = j + dx, y = i + dy;
						if(0 <= x && x < w && 0 <= y && y < h) {
							ans[y][x] = '.';
						}
					}
				}
			}
		}
	}
	
	auto rev = ans;
	
	for(int i = 0; i < h; ++i) {
		for(int j = 0; j < w; ++j) {
			if(ans[i][j] == '#') {
				for(int dx = -1; dx <= 1; ++dx) {
					for(int dy = -1; dy <= 1; ++dy) {
						int x = j + dx, y = i + dy;
						if(0 <= x && x < w && 0 <= y && y < h) {
							rev[y][x] = '#';
						}
					}
				}
			}
		}
	}
	
	if(rev != pic) {
		cout << "impossible" << endl;
	} else {
		cout << "possible" << endl;
		for(int i = 0; i < h; ++i) {
			cout << ans[i] << endl;
		}
	}
	
	return 0;
}