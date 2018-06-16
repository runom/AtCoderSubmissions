#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int a,b,c;
	int N;
	scanf("%d%d%d%d",&a,&b,&c,&N);
	printf("%d %d %d\n",(N-a)>0?(N-a):0,(N*2-b)>0?(N*2-b):0,(N*3-c)>0?(N*3-c):0);
}