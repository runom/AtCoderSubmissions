#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int R, C, M, N;
	int a[51][51] = {};
	int r1[5001], r2[5001], c1[5001], c2[5001]; 
	cin >> R >> C >> M >> N;
	
	for(int i = 0; i < N; ++i) {
		cin >> r1[i] >> r2[i] >> c1[i] >> c2[i];
		for(int j = r1[i]; j <= r2[i]; ++j) {
			for(int k = c1[i]; k <= c2[i]; ++k) {
				++a[j][k];
			}
		}
	}
	
	int sum = 0;
	
	for(int i = 1; i <= R; ++i) {
		for(int j = 1; j <= C; ++j) {
			a[i][j] %= 4;
			if(a[i][j] == 0) sum++;
		}
	}
	
	
	for(int i = 0; i < N; ++i) {
		int t = 0;
		for(int j = r1[i]; j <= r2[i]; ++j) {
			for(int k = c1[i]; k <= c2[i]; ++k) {
				if(a[j][k] == 1) ++t;
				if(a[j][k] == 0) --t;
			}
		}
		
		if(sum + t == M) {
			cout << i + 1 << endl;
		}
	}

}