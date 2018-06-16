#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
	int l[3];
	cin >> l[0] >> l[1] >> l[2];
	int maxi = l[0] + l[1] + l[2];
	
	int mini;
	if(l[0] + l[1] < l[2]) {
		mini = l[2] - l[0] - l[1];
	} else if(l[1] + l[2] < l[0]){
		mini = l[0] - l[1] - l[2];
	} else if(l[0] + l[2] < l[1]){
		mini = l[1] - l[0] - l[2];
	} else {
		mini = 0;
	}
	
	cout << fixed;
	cout << acos(-1) * maxi * maxi - acos(-1) * mini * mini << endl;
	
	return 0;
}