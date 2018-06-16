#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const long long MOD = 1e9+7;
const int N = 1e6;
long long inv[N];
long long fact[N];
long long fact_inv[N];

int main()
{
    for (long long i = 1; i < N; i++) {
        inv[i] = (i == 1) ? 1 : (MOD - (MOD / i) * inv[MOD % i] % MOD);
    }

    fact[0] = 1;
    fact_inv[0] = 1;

    for(int i = 1; i < N; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
    }

    int h, w, a, b;
    cin >> h >> w >> a >> b;

    long long ans = 0;
    for(int i = 0; i < w - b; ++i) {
        long long x = fact[(h - a - 1) + (b + i)] * fact_inv[h - a - 1] % MOD * fact_inv[b + i] % MOD;
        long long y = fact[(a - 1) + (w - b - 1 - i)] * fact_inv[a - 1] % MOD * fact_inv[w - b - 1 - i] % MOD;
        ans += x * y % MOD;
        ans %= MOD;
    }    
    cout << ans % MOD << endl;
}