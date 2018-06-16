/*** Template Begin ***/

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

using namespace std;

#ifdef USING_BOOST

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

#define USING_NAMESPACE
#ifdef USING_NAMESPACE
using namespace std;

#ifdef USING_BOOST
using namespace boost;
using namespace boost::adaptors;
#endif
#endif

/*** Template End ***/

int main() {
    int n = in<int>();
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        in(x[i], y[i]);
    }

    int64_t a = 0, b = 0, c = 0;

    const double pi = acos(-1);
    const double eps = 1e-13;

    for (int i = 0; i < n; i++) {
        vector<double> theta;
        theta.reserve(2 * (n - 1));
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;

            theta.push_back(atan2(y[j] - y[i], x[j] - x[i]));
            // if (theta.back() < 0) {
            //     theta.back() += 2 * pi;
            // }
        }

        sort(theta.begin(), theta.end());
        for (int j = 0; j < n - 1; j++) {
            theta.push_back(theta[j] + 2 * pi);
        }

        int r = 0, l = 0;
        for (int index = 0; index < n - 1; ++index) {
            while (r < theta.size() && theta[r] - theta[index] < pi) {
                r++;
            }

            while (l < theta.size() &&
                   theta[l] - theta[index] < pi / 2.0 - eps) {
                l++;
            }

            int m = l;

            while (l < theta.size() &&
                   theta[l] - theta[index] <= pi / 2.0 + eps) {
                l++;
            }

            b += l - m;
            c += r - l;
        }

        // for (int j = 0; j < n - 1; j++) {
        //     int x = lower_bound(theta.begin(), theta.end(), theta[j] + pi /
        //     2) -
        //             theta.begin();
        //     int y = upper_bound(theta.begin(), theta.end(), theta[j] + pi /
        //     2) -
        //             theta.begin();
        //     int z = lower_bound(theta.begin(), theta.end(), theta[j] + pi) -
        //             theta.begin();

        //     b += y - x;
        //     c += z - y;
        // }
    }

    a = (int64_t)n * (n - 1) * (n - 2) / 6 - (b + c);

    out(a, b, c);
}
