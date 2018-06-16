#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;

    vector<ll> is_prime(pow(*max_element(a.begin(), a.end()), 1.0 / 3.0) + 3,
                        1);
    vector<ll> primes;
    primes.reserve(is_prime.size());
    is_prime[0] = 0;
    is_prime[1] = 0;

    for (int i = 2; i < is_prime.size(); ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j < is_prime.size(); j += i) {
                is_prime[j] = 0;
            }
        }
    }

    map<ll, int> cnt;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < primes.size(); ++j) {
            if (primes[j] * primes[j] * primes[j] > a[i]) break;

            while (a[i] % (primes[j] * primes[j] * primes[j]) == 0) {
                a[i] /= primes[j] * primes[j] * primes[j];
            }
        }
        cnt[a[i]]++;
    }

    int ans = 0;
    if (cnt[1] > 0) ans++;

    set<ll> used;

    for (auto& x : cnt) {
        if (x.first == 1) continue;

        if (used.count(x.first)) continue;

        ll y = x.first;
        ll z = 1;
        for (int j = 0; j < primes.size(); ++j) {
            auto divide = primes[j] * primes[j];
            if (y < divide) break;
            if (y % divide == 0) {
                y /= divide;
                z *= primes[j];
            }
        }

        ll w = sqrt(y);
        if (w * w == y) {
            y = 1;
            z *= w;
        }

        z *= y * y;

        if (cnt.count(z)) {
            ans += max(x.second, cnt[z]);
            used.insert(z);
        } else {
            ans += x.second;
        }
    }

    cout << ans << endl;
}