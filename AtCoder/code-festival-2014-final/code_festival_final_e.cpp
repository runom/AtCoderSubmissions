#include <iostream>
#include <limits>
using namespace std;


int n;
int a[3001];


int main() {
	
	int hi[3001] = {};
	int lo[3001] = {};
	
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	if(n < 3) {
		cout << 0 << endl;
		return 0;
	}
	
	for(int i = 0; i < n; ++i) {
		
        /*
		for(int i = 0; i < n; ++i) {
			cout << hi[i] << ' ';
		} cout << endl;
		for(int i = 0; i < n; ++i) {
			cout << lo[i] << ' ';
		} cout << endl;
		
		cout << endl;
         */
		if(hi[i] == 0) {
			hi[i] = 1;
		}
		
		if(lo[i] == 0) {
			lo[i] = 1;
		}
		
		for(int j = i + 1; j < n; ++j) {
			
			if(a[i] > a[j]) {
				hi[j] = max(hi[j], lo[i] + 1);
			} else if(a[i] < a[j]){
				lo[j] = max(lo[j], hi[i] + 1);
			}
		}
        /*
        for(int i = 0; i < n; ++i) {
			cout << hi[i] << ' ';
		} cout << endl;
		for(int i = 0; i < n; ++i) {
			cout << lo[i] << ' ';
		} cout << endl;
		cout << endl;
         */
	}
	
    int ans = max(hi[n - 1], lo[n - 1]);
    
	cout << (ans > 2 ? ans : 0) << endl;
	
	return 0;
}
