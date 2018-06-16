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

template <typename T, size_t D>
struct multi_vector_type {
    using type = std::vector<typename multi_vector_type<T, D - 1>::type>;
};

template <typename T>
struct multi_vector_type<T, 1> {
    using type = std::vector<T>;
};

template <typename T>
struct multi_vector_type<T, 0> {
    using type = T;
};

template <typename T, size_t D>
using multi_vector = typename multi_vector_type<T, D>::type;

template <typename T, size_t D, class = typename std::enable_if<D == 0>::type>
T make_vector(const T &val = T()) {
    return val;
}

template <typename T, size_t D = 1, typename... Ts,
          class = typename std::enable_if<D != 0>::type>
multi_vector<T, D> make_vector(size_t n, Ts &&... args) {
    return multi_vector<T, D>(n, make_vector<T, D - 1>(args...));
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

multi_vector<int, 3> a;
multi_vector<int, 3> memo;

int h, w;

int dfs(int i, int j, int k) {
    if (j == h && k == h) {
        return 0;
    }

    if (memo[i][j][k] != -1) {
        return memo[i][j][k];
    }

    auto ret = 1 << 29;

    if (j != h) {
        ret = min(ret, dfs(i, j + 1, k) + a[i][j][k]);
    }

    if (k != h) {
        ret = min(ret, dfs(i, j, k + 1) + a[i][j][k]);
    }

    return memo[i][j][k] = ret;
}

int main() {
    in(h, w);

    a = make_vector<int, 3>(w, h + 1, h + 1);
    memo = make_vector<int, 3>(w, h + 1, h + 1, -1);

    auto c = vin<string>(h);

    for (int k : rep(0, w - 1)) {
        for (int i : rep(0, h)) {
            int cnt = 0;
            for (int j : rep(0, h - i)) {
                if (c[j][k] == c[j + i][k + 1]) {
                    cnt++;
                }
            }
            a[k][i][0] = cnt;
        }

        for (int i : rep(0, h)) {
            int cnt = 0;
            for (int j : rep(0, h - i)) {
                if (c[j + i][k] == c[j][k + 1]) {
                    cnt++;
                }
            }
            a[k][0][i] = cnt;
        }

        for (int i : rep(1, h)) {
            for (int j : rep(1, h)) {
                a[k][i][j] =
                    a[k][i - 1][j - 1] - (c[h - i][k] == c[h - j][k + 1]);
            }
        }
    }

    int sum = 0;
    for (int i : rep(0, w - 1)) {
        sum += dfs(i, 0, 0);
    }
    out(sum);
}
