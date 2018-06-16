#include <iostream>
using namespace std;

int main()
{
	int n;
	int ans;
	cin >> n;
	ans=n/10*100;
	ans += n%10<7?(n%10)*15:100;
	cout <<  ans << endl;
}