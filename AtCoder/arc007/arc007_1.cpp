#include <iostream>
#include <string>
using namespace std;

int main()
{
	char c;
	string s;
	cin >>c;
	cin >>s;
	for(int i=0;i<s.size();++i){
		if(s[i]==c)continue;
		cout << s[i];
	}
	cout << endl;
}