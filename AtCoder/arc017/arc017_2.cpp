#include <iostream>
using namespace std;

int a[300001];
int ren[3000001];

int main() {
	int N, K;
	int ans = 0;
	cin >> N >> K;
	
	if(K == 1) {
		cout << N << endl;
		return 0;
	}
	
	cin >> a[0];
	ren[0] = 0;
	
	for(int i = 1; i < N; ++i) {
		cin >> a[i];
		if(a[i-1] < a[i]) {
			ren[i] = ren[i-1] + 1;
			if(ren[i] == K - 1){
				ans++;
				ren[i]--;
			} 
		} else {
			ren[i] = 0;
		}
	}
	
	cout << ans << endl;
	return 0;
}