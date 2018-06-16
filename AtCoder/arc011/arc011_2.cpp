#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	int n;
	string s[1000];
	string t[1001];
	cin >> n;
	for(int i = 0; i < n; ++i)cin >> s[i];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < s[i].size(); ++j){
			switch(tolower(s[i][j])){
			  case 'b':
			  case 'c':
				t[i] += '1';
				break;
			  case 'd':
			  case 'w':
				t[i] += '2';
				break;
			  case 't':
			  case 'j':
				t[i] += '3';
				break;
			  case 'f':
			  case 'q':
				t[i] += '4';
				break;
			  case 'l':
			  case 'v':
				t[i] += '5';
				break;
			  case 's':
			  case 'x':
				t[i] += '6';
				break;
			  case 'p':
			  case 'm':
				t[i] += '7';
				break;
			  case 'h':
			  case 'k':
				t[i] += '8';
				break;
			  case 'n':
			  case 'g':
				t[i] += '9';
				break;
			  case 'z':
			  case 'r':
				t[i] += '0';
				break;
			}
		}
	}
	bool f = false;
	for(int i = 0; i < n; ++i){
		if(t[i].size()==0)continue;
		if(f)cout << ' ';
		cout << t[i];
		f = true;
	}
	cout << endl;
}