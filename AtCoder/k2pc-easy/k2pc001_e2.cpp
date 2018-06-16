#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	int N;
	int a[10];
	char c[100][7];
	int cmax[7]={0};
	int count[7]={0};
	scanf("%d",&N);
	for(int i=0;i<10;++i){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<N;++i){
			scanf("%s",c[i]);
	}
	sort(a,a+10,greater<int>());
	for(int i=0;i<N;++i){
		for(int j=0;j<7;++j){
			if(c[i][j]=='X'){
				count[j]++;
			}
			else {
				cmax[j] = max(count[j],cmax[j]);
				count[j] = 0;
			}
		}
	}
	for(int i=0;i<7;++i){
		cmax[i] = max(count[i],cmax[i]);
	}	
	
	sort(cmax,cmax+7,greater<int>());
	
	bool f=true;
	for(int i=0;i<7;++i){
		if(a[i]<cmax[i]){
			f=false;
		}
	}
	
	if(f){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	
}	
	
	