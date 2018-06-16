#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<string> set;
    vector<string> list(n);
    for(int i = 0; i < n; ++i){
        cin >>list[i];
    }
    set.insert(list[0]);
    for(int i = 1; i < n; ++i){
        if (set.count(list[i]) || list[i].front() != list[i-1].back()) {
            cout << (i % 2 ? "WIN" : "LOSE") << endl;
            return 0;
        }
        set.insert(list[i]);
    }
    cout << "DRAW" << endl;
}