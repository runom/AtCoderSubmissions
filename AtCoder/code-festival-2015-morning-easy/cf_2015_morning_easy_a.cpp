#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <utility>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> v(10001);
    
    for(int i = 1; i <= 100; ++i) {
        v[i * i] = 1;
    }
    
    for(int i = n; i <= 10000; ++i) {
        if(v[i] == 1) {
            cout << i - n << endl;
            return 0;
        }
    }
}
