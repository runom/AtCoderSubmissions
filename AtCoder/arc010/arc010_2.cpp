#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int t[12][31];
int moon[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

int main()
{
	int n,ans = 0,sum = 0;
	int count = 0,a = 0;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int m,d;
		scanf("%d/%d",&m,&d);
		t[m-1][d-1] = 1;
	}
	
	for(int i = 0; i < 12; ++i){
		for(int j = 0; j < moon[i]; ++j){
			++sum;
			if (sum % 7 == 0 || sum % 7 ==1){
				if(t[i][j]){
					++a;
				}
				++count;
			}
			else if(t[i][j]){
				++count;
			}
			else if(a){
				--a;
				++count;
			}
			else{
				ans = max(ans,count);
				count = 0;
			}
			
		}
	}
	ans = max(ans,count);
	printf("%d\n",ans);
}