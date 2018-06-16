#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    int v[] = {1, 2, 3, 4, 5, 6};
 
    int index = 0;
    for (int i = 0; i < n; ++i) {
        swap(v[index], v[index + 1]);
        index++;
        if (index == 5) {
            index = 0;
        }
    }
 
    for (int i = 0; i < 6; ++i) {
        cout << v[i];
    }
    cout << endl;
}