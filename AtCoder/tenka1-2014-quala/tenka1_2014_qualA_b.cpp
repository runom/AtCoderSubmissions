#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int kaburin = 5;
	int ret[1000050] = {};
	int hit[1000050] = {};
	long long int ans = 0;
	int comb = 0;
	int tame = -1;
	vector<int> v;
	
	string in;
	cin >> in;
	
	for(int i = 0; i < (int)in.size(); ++i) {
		if(hit[i] != 0) {
			comb++;
		}
		
		kaburin += ret[i];
		
		if(tame > 0) {
			tame--;
			continue;
		} else if(tame == 0){
			tame--;
			ret[i + 7] = 3;
			continue;
		}
		
		if(in[i] == 'N' && kaburin >= 1) {
			kaburin--;
			ret[i + 7] = 1;
			hit[i + 2] = 10 + comb/10;
		} else if(in[i] == 'C' && kaburin >= 3) {
			tame = 1;
			kaburin -= 3;
			hit[i + 4] = 50 + 5 * (comb/10);
		} 
	}
	
	for(auto x : hit) {
		ans += x;
	}
	
	cout << ans << endl;
}