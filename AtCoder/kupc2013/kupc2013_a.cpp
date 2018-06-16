#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<pair<int,string>> v(n+1);
    v[0] = pair<int,string>(0,"kogakubu10gokan");
    for(int i = 0; i < n; ++i){
        cin >> v[i + 1].first >> v[i + 1].second;
    }
    sort(v.begin(), v.end());
    
    for(int i = 0; i < v.size(); ++i){
        if(q < v[i].first){
            cout << v[i-1].second << endl;
            return 0;
        }
    }
    cout << v.back().second << endl;
}