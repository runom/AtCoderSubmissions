#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,m,k=0,l;
	int d[105]={0};
	cin >> n >>m;
	
	for(int i=1;i<n+1;++i){
		d[i]=i;
	}
	for(int i=0;i<m;++i){
		cin >> l;
		for(int j=1;j<n+1;++j){
			if(l==d[j]){
				swap(k,d[j]);
				break;
			}
		}
	}
	for(int i=1;i<n+1;++i){
		cout << d[i] << endl;
	}
}