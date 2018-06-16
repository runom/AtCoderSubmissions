#include <iostream>
using namespace std;

int main()
{
    int n,v,w,x,y,z,ans = 0;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> v >> w >> x >> y >> z; 
        if(v + w + x + y + z < 20) ans++;
    }
    
    cout << ans << endl;
    
}