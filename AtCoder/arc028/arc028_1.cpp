#include <iostream>
using namespace std;

int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	n %= a + b;
	if(n != 0 && n <= a) {
		cout << "Ant" << endl;
	} else {
		cout << "Bug" << endl;
	}
}