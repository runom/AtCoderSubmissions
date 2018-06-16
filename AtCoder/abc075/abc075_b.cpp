#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	
	vector<string> a(h);
	
	for(int i = 0; i < h; ++i) {
		cin >> a[i];
	}
	
	for(int i = 0; i < h; ++i) {
		for(int j = 0; j < w; ++j) {
			if(a[i][j] == '#') {
				cout << '#';
				continue;
			}
			
			int cnt = 0;
			
			for(int dx : {-1, 0, 1}) {
				for(int dy : {-1, 0, 1}) {
					int x = j + dx;
					int y = i + dy;
					
					if(x < 0 || w <= x) {
						continue;
					}
					if(y < 0 || h <= y) {
						continue;
					}
					
					cnt += a[y][x] == '#';
				}
			}
			
			cout << cnt;
		}
		cout << endl;
	}
	return 0;
}