#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main()
{
    vector<int> v(11);

    for(int i = 0; i < 3; ++i) {
        int x;
        cin >> x;
        v[x]++;
    }

    cout << (v[5] == 2 && v[7] == 1 ? "YES" : "NO") << endl;
}