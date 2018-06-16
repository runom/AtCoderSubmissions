#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    int g[20][20] = {};
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        
        x--;
        y--;
        
        g[x][y] = 1;
        g[y][x] = 1;
    }
    
    int ans = 0;
    for(int i = 0; i < (1 << n); ++i){
        bool f = true;
        for(int j = 0; j < n; ++j){
           for(int k = j + 1; k < n; ++k){
               if((i & (1 << j)) && (i & (1 << k))) {
                   if(!(g[j][k])) {
                       f = false;
                   }
               }
           }
        }
        if(f){
            int cnt = 0;
            for(int k = 0; k < n; ++k){
                if(i & (1 << k)){
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        }
    }
    
    cout << ans << endl;
}
            