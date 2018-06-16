#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <deque>
#include <map>
using namespace std;

typedef pair<int,deque<char>> P;
deque<char> deq;
map<P,int> memo;
string s;
int n;
int dfs(int i){
    if(i == n){
        return deq.size();
    }
    if(memo.count(P(i,deq))){
        return memo[P(i,deq)];
    }
    int res = 1 << 30;
    if(!deq.empty() && s[i] == deq.front()){
        deq.pop_front();
        res = min(res,dfs(i + 1));
        deq.push_front(s[i]);
    } else if(!deq.empty() && s[i] == deq.back()){
        deq.pop_back();
        res = min(res,dfs(i + 1));
        deq.push_back(s[i]);
    } else {
        deq.push_front(s[i]);
        res = min(res,dfs(i+1));
        deq.pop_front();
        
        deq.push_back(s[i]);
        res = min(res,dfs(i+1));
        deq.pop_back();
    }
    memo[P(i,deq)] = res;
    return res;
}

int main()
{
    cin >> n >> s;
    cout << dfs(0) << endl;
}