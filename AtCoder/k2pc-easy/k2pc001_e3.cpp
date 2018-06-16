#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int i,j;
	scanf("%d%d",&i,&j);
	int n1=1,m1=1,n2=1,m2=1,n,m;
	for(int k=2;k<=i;++k){
		if(n1==1){
			n1+=m1;
			m1=1;
		}else{
			n1--;
			m1++;
		}
	}
	for(int k=2;k<=j;++k){
		if(n2==1){
			n2+=m2;
			m2=1;
		}else{
			n2--;
			m2++;
		}
	}
	
	n=n1+n2;
	m=m1+m2;
	int l=n+m-1;
	printf("%d\n",((l-1)*l/2+m));
}