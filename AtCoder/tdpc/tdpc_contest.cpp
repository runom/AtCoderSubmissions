#include <iostream>
using namespace std;

bool dp[10001];

int main()
{
    int n, p;
    cin >> n;
    
    dp[0] = true;
    for(int i = 0; i < n; ++i){
        cin >> p;
        for(int j = 10001; j >= 0; --j){
            if(dp[j] && j + p < 10001){
                dp[j+p] = true;
            }
        }
    }
    
    int count = 0;
    for(int i = 0; i < 10001; ++i){
        if(dp[i]) count++;
    }
    cout << count << endl;
    
}