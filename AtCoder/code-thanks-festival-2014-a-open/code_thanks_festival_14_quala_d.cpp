#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N, Q;
	cin >> N >> Q;
	
	for(int i = 0; i < Q; ++i) {
		int a, b, s, t;
		cin >> a >> b >> s >> t;
		
		if(a <= s && t <= b) {
			cout << 0 << endl;
		} else if(t <= a || b <= s) {
			cout << (t - s) * 100 << endl;
		} else if(s <= a && b <= t) {
			cout << ((t - s) - (b - a)) * 100 << endl;
		} else if(a <= s){
			cout << (t - s - (b - s)) * 100 << endl;
		} else {
			cout << (t - s - (t - a)) * 100 << endl;
		}
	}
}