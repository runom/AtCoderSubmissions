#include <cstdio>
using namespace std;

int main()
{
	int n,m,N;
	int p,q;
	int ans = 0;
	scanf("%d%d%d",&m,&n,&N);
	ans += N;
	q = N;
	while(q>=m){
		ans += q / m * n;
		q = q % m + q / m * n;
	}
	printf("%d\n",ans);
}