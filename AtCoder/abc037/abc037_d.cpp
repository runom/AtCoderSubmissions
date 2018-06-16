#include <bits/stdc++.h>
#define FOR(i,a,b)  for(int (i)=(a);(i)<(b);(i)++)
#define REP(i,n)    FOR(i,0,n)
#define RER(i,n)    FOR(i,0,(n+1))
#define pb          push_back
#define mp(a,b)     make_pair((a),(b))
#define mset(m,v)   memset(m,v,sizeof(m))
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pair<ll, ll> > vpll;
typedef vector<string> vs;
typedef long double ld;
const double EPS    = 1e-10;
const int INF       = 1e+9;
const double PI     = acos(-1);
 
const ll MOD = 1e9 + 7;
int h, w;
vector<vector<ll>> grid(1001, vector<ll>(1001, 0));
vector<vector<ll>> memo(1001, vector<ll>(1001, 0));
 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
 
ll dfs(int i, int j, int cur)
{
    if ( memo[i][j] != 0 ) {
        return memo[i][j];
    }
 
    ll ans = 1;
    REP(k, 4) {
        int ny = i + dy[k];
        int nx = j + dx[k];
        if ( nx >= 0 && nx < w && ny >= 0 && ny < h && grid[ny][nx] > cur ) {
            ans = (ans + (dfs(ny, nx, grid[ny][nx]) % MOD)) % MOD;
        }
    }
 
    return memo[i][j] = ans;
}
 
auto main() -> int
{
    cin >> h >> w;
    REP(i, h) {
        REP(j, w) {
            cin >> grid[i][j];
        }
    }
 
    ll ans = 0;
    REP(i, h) {
        REP(j, w) {
            ans = (ans + (dfs(i, j, grid[i][j]) % MOD)) % MOD;
        }
    }
 
    cout << ans % MOD << endl;
 
    return 0;
}