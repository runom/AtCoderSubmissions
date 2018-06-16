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

int64_t n, w;
vector<int64_t> a, b;

// n <= 30
int64_t solve1() {
    int n1 = n / 2;
    int n2 = n - n1;

    vector<pair<int64_t, int64_t>> s(1 << n1);
    for (int i = 0; i < (1 << n1); ++i) {
        int64_t v_sum = 0, w_sum = 0;
        for (int j = 0; j < n1; ++j) {
            if (i & (1 << j)) {
                v_sum += a[j];
                w_sum += b[j];
            }
        }

        if (w - w_sum >= 0) {
            s[i].first = w_sum;
            s[i].second = v_sum;
        }
    }

    sort(s.begin(), s.end(), [](auto x, auto y) {
        return x.first == y.first ? x.second > y.second : x.first < y.first;
    });

    vector<pair<int64_t, int64_t>> t;

    for (int i = 0; i < s.size(); ++i) {
        if (t.empty() || t.back().second < s[i].second) {
            t.push_back(s[i]);
        }
    }

    swap(s, t);

    int64_t ans = 0;

    for (int i = 0; i < (1 << n2); ++i) {
        int64_t v_sum = 0, w_sum = 0;
        for (int j = 0; j < n2; ++j) {
            if (i & (1 << j)) {
                v_sum += a[n1 + j];
                w_sum += b[n1 + j];
            }
        }

        if (w - w_sum < 0) continue;

        auto it = lower_bound(s.begin(), s.end(),
                              pair<int64_t, int64_t>(w - w_sum, 1LL << 60)) -
                  1;
        ans = max(ans, v_sum + it->second);
    }

    return ans;
}

// n <= 200 && 1 <= w_i(b_i) <= 1000
int64_t solve2() {
    w = min(w, n * 1000);

    auto dp = make_vector<int64_t, 2>(n + 1, w + 1);

    // dp[i][0] = 0
    // dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - b[i - 1]] + a[i - 1])

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= w; ++j) {
            dp[i + 1][j] = max(dp[i + 1][j - 1], dp[i][j]);
            if (j - b[i] >= 0) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - b[i]] + a[i]);
            }
        }
    }

    return dp[n][w];
}

// n <= 200 && 1 <= v_i(a_i) <= 1000
int64_t solve3() {
    int64_t v = n * 1000;

    auto dp = make_vector<int64_t, 2>(n + 1, v + 1, 1LL << 60);

    // dp[i][0] = 0
    // dp[i + 1][j] = dp[i][j], dp[i][j - v[i]] + w[i]

    for (int i = 0; i < n; ++i) {
        dp[i][0] = 0;
        for (int j = 0; j <= v; ++j) {
            if (j - a[i] < 0) {
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = min(dp[i][j], dp[i][j - a[i]] + b[i]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= v; ++i) {
        if (dp[n][i] <= w) {
            ans = max(ans, i);
        }
    }

    return ans;
}

int main() {
    in(n, w);
    for (int i = 0; i < n; ++i) {
        int x, y;
        in(x, y);
        a.push_back(x);
        b.push_back(y);
    }

    if (n <= 30) {
        out(solve1());
    } else if (*max_element(b.begin(), b.end()) <= 1000) {
        out(solve2());
    } else if (*max_element(a.begin(), a.end()) <= 1000) {
        out(solve3());
    } else {
        assert(false);
    }
}