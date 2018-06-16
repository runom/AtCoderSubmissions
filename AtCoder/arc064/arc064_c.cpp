/*** Template Begin ***/

#define USING_BOOST
#define USING_NAMESPACE

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
    std::cout << std::setprecision(10);
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

template <char delimiter = ' ', typename T>
inline void vout(const T &v, int h, int w) {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (j) std::cout << delimiter;
            std::cout << v[i][j];
        }
        std::cout << std::endl;
    }
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

#ifdef USING_BOOST

#include <boost/math/common_factor.hpp>
#include <boost/range.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/algorithm_ext.hpp>
#include <boost/range/irange.hpp>

inline auto rep(int begin, int end) {
    if (begin > end) {
        return boost::irange(0, 0);
    } else {
        return boost::irange(begin, end);
    }
}

inline auto rep(int begin, int end, int step) {
    if ((step > 0 && begin > end) || (step < 0 && begin < end)) {
        return boost::irange(0, 0, step);
    } else {
        return boost::irange(begin, end, step);
    }
}

#endif

#ifdef USING_NAMESPACE
using namespace std;

#ifdef USING_BOOST
using namespace boost;
using namespace boost::adaptors;
#endif
#endif

/*** Template End ***/

vector<vector<double>> cost;
vector<double> d;
vector<bool> used;
int V;

const double inf = 1e10;

double dijkstra(int s, int g) {
    d[s] = 0;

    while (true) {
        int v = -1;

        for (int u : rep(0, V)) {
            if (!used[u] && (v == -1 || d[u] < d[v])) {
                v = u;
            }
        }

        if (v == -1) {
            break;
        }

        used[v] = true;

        for (int u : rep(0, V)) {
            d[u] = min(d[u], d[v] + cost[v][u]);
        }
    }

    return d[g];
}

int main() {
    int64_t sx, sy, gx, gy;
    in(sx, sy, gx, gy);

    int n;
    in(n);

    V = n + 2;
    cost = make_vector<double, 2>(n + 2, n + 2, inf);
    d = vector<double>(n + 2, inf);
    used = vector<bool>(n + 2, false);

    vector<int64_t> x(n), y(n), r(n);
    for (int i : rep(0, n)) {
        in(x[i], y[i], r[i]);
    }

    for (int i : rep(0, n + 2)) {
        cost[i][i] = 0;
    }

    cost[0][1] = sqrt(pow(sx - gx, 2) + pow(sy - gy, 2));
    cost[1][0] = sqrt(pow(sx - gx, 2) + pow(sy - gy, 2));

    for (int i : rep(0, n)) {
        double d = sqrt(pow(sx - x[i], 2) + pow(sy - y[i], 2)) - r[i];

        if (d < 0) {
            d = 0;
        }

        cost[0][i + 2] = d;
        cost[i + 2][0] = d;
    }

    for (int i : rep(0, n)) {
        double d = sqrt(pow(gx - x[i], 2) + pow(gy - y[i], 2)) - r[i];

        if (d < 0) {
            d = 0;
        }

        cost[1][i + 2] = d;
        cost[i + 2][1] = d;
    }

    for (int i : rep(0, n)) {
        for (int j : rep(0, n)) {
            double d =
                sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)) - (r[i] + r[j]);

            if (d < 0) {
                d = 0;
            }

            cost[i + 2][j + 2] = d;
            cost[j + 2][i + 2] = d;
        }
    }
    out(dijkstra(0, 1));
}