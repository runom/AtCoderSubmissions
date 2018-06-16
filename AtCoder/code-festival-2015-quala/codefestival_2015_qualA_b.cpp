#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <functional>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int ans = A[0];
	for(int i = 1; i < N; ++i) {
		ans = ans + A[i] + ans;
	}
	
	cout << ans << endl;
	return 0;
}