#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

auto init_ = [] {
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed;
    return 0;
}();

template <typename T>
inline T in() {
    T x;
    std::cin >> x;
    return x;
}

template <typename T>
inline void in(T &x) {
    std::cin >> x;
}

template <typename T, typename... Ts>
inline void in(T &t, Ts &... ts) {
    std::cin >> t;
    in(ts...);
}

template <typename T, typename U = std::vector<T>>
inline U vin(int n) {
    U v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    return v;
}

template <typename T, typename U = std::vector<T>, typename V = std::vector<U>>
inline V vin(int h, int w) {
    V vv(h, U(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            std::cin >> vv[i][j];
        }
    }
    return vv;
}

template <typename T>
inline void out(const T &x) {
    std::cout << x << std::endl;
}

template <char delimiter = ' ', typename T, typename... Ts>
inline void out(const T &t, const Ts &... ts) {
    std::cout << t << delimiter;
    out(ts...);
}

template <char delimiter = ' ', typename T>
inline void vout(const T &v, int n) {
    for (int i = 0; i < n; ++i) {
        if (i) std::cout << delimiter;
        std::cout << v[i];
    }
    std::cout << std::endl;
}

using namespace std;

#define BOOST
#ifdef BOOST

#include <boost/range.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/algorithm_ext.hpp>
#include <boost/range/irange.hpp>
using namespace boost;
using namespace boost::adaptors;

inline auto rep(int begin, int end) {
    if (begin > end) {
        return irange(0, 0);
    } else {
        return irange(begin, end);
    }
}

inline auto rep(int begin, int end, int step) {
    if ((step > 0 && begin > end) || (step < 0 && begin < end)) {
        return irange(0, 0, step);
    } else {
        return irange(begin, end, step);
    }
}

#endif

int main() {
    typedef long long ll;

    ll n = in<ll>();
    auto t = vin<ll>(n);
    auto a = vin<ll>(n);

    if (t.back() != a.front()) {
        out(0);
        return 0;
    }

    vector<ll> f1(n), f2(n), mini(n, 1LL << 53);

    f1[0] = t[0];
    for (int i : rep(1, n)) {
        if (t[i] != t[i - 1]) {
            f1[i] = t[i];
        }

        mini[i] = min(mini[i], t[i]);
    }

    f2[n - 1] = a[n - 1];
    for (int i : rep(0, n - 1) | reversed) {
        if (a[i] != a[i + 1]) {
            f2[i] = a[i];
        }

        mini[i] = min(mini[i], a[i]);
    }

    for (int i : rep(0, n)) {
        if ((f1[i] != 0 && t[i] > a[i]) || (f2[i] != 0 && a[i] > t[i])) {
            out(0);
            return 0;
        }

        if (f1[i] != 0 && f2[i] != 0 && f1[i] != f2[i]) {
            out(0);
            return 0;
        }
    }

    ll ans = 1;
    const ll mod = 1000000000 + 7;

    for (int i : rep(1, n - 1)) {
        if (f1[i] == 0 && f2[i] == 0) {
            ans *= mini[i];
            ans %= mod;
        }
    }

    out(ans);
}