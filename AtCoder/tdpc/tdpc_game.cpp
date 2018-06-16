#include <iostream>
#include <algorithm>
#include <complex>
using namespace std;
typedef complex<int> P;

int A, B;
int a[1001], b[1001];
P memo[1002][1002][2];

P dfs(int i, int j, int k)
{
    if(i == A && j == B) return P();
    if(memo[i][j][k] != P(-1,-1)) {
        return memo[i][j][k];
    }
    P res;
    if(k){
        if(i == A) res = dfs(i, j + 1, !k) + P(b[j], 0);
        else if(j == B) res = dfs(i + 1, j, !k) + P(a[i], 0);
        else {
            P p1 = dfs(i + 1, j, !k) + P(a[i], 0);
            P p2 = dfs(i, j + 1, !k) + P(b[j], 0);
            if(p1.real() < p2.real()) res = p2;
            else res = p1;
        }
    }
    else {
        if(i == A) res = dfs(i, j + 1, !k) + P(0, b[j]);
        else if(j == B) res = dfs(i + 1, j, !k) + P(0, a[i]);
        else {
            P p1 = dfs(i + 1, j, !k) + P(0, a[i]);
            P p2 = dfs(i, j + 1, !k) + P(0, b[j]);
            if(p1.imag() < p2.imag()) res = p2;
            else res = p1;
        }
    }
    return memo[i][j][k] = res;
}

int main()
{
    fill((P*)memo, (P*)(memo + 1001), P(-1, -1));
    cin >> A >> B;
    for(int i = 0; i < A; ++i) cin >> a[i];
    for(int i = 0; i < B; ++i) cin >> b[i];
    cout << dfs(0, 0, 1).real() << endl;
}