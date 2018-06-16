#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,m,l,ans = 0;
	int a[3];
	cin >> n >> m >> l;
	for(int i = 0; i < 3; ++i){
		cin >> a[i];
	}
	sort(a,a+3);
	do{
		ans = max(ans,(n / a[0]) * (m / a[1]) * (l / a[2]));
	}while(next_permutation(a,a+3));
	
	cout << ans << endl;
}