#include <iostream>
using namespace std;

int main()
{
	int n,m,a,b;
	int c[100];
	cin >> n >> m >> a >> b;
	for(int i = 0; i < m; ++i){
		cin >> c[i];
	}
	for(int i = 0; i < m; ++i){
		if(n <= a){
			n += b;
		}
		n -= c[i];
		if(n<0){
			cout << i + 1 << endl;
			break;
		}
		if(i == m-1){
			cout << "complete" << endl;
		}
	}
}