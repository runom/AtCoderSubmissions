#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	
	sort(a, a + 3);
	
	int ans = 0;
	int sum = 0;
	int index = 2;
	while(sum < N) {
		sum += a[index--];
		ans++;
		if(index == -1) index = 2;
	}
	
	
	cout << ans << endl;
	
}