#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	
	vector<int> Ps(N);
	
	for(int i = 0; i < N; ++i) {
		cin >> Ps[i];
	}
	
	int ans = 0;
	
	for(int i = 0; i < M; ++i) {
		int s;
		cin >> s;
		
		ans += Ps[s-1];
	}
	
	cout << ans << endl;
}