#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int a[3];
	int b[3] = {};
	scanf("%d",&n);
	for(int i = 0; i < n; ++i){
		scanf("%d %d %d",a, a + 1, a + 2);
		sort(a,a + 3);
		for(int j = 0; j < 3; ++j){
			b[j] = max(b[j],a[j]);
		}
	}
	printf("%d\n",b[0] * b[1] * b[2]);
}