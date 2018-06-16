/*** Template Begin ***/

#pragma region template

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
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

typedef int64_t i64;
typedef uint64_t u64;

auto init_ = [] {
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed;
    return 0;
}();

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

namespace detail {

template <typename F>
struct Debug {
    const char *delim_ = "\n";
    F fun;

    Debug(F f) : fun(f) {}

    ~Debug() { fun(delim_); }

    Debug &delim(const char *d) {
        delim_ = d;
        return *this;
    }
};

std::deque<std::string> split(const std::string &s, char c) {
    std::deque<std::string> v;
    std::stringstream ss(s);
    std::string x;
    while (std::getline(ss, x, c)) v.emplace_back(x);
    return v;
}

template <typename T>
void deb(const char *delim, std::deque<std::string> v, T a) {
    std::cerr << v[0].substr(v[0][0] == ' ', v[0].length()) << " = " << a
              << '\n';
    std::cerr << std::flush;
}

template <typename T, typename... Args>
void deb(const char *delim, std::deque<std::string> v, T a, Args... args) {
    std::cerr << v[0].substr(v[0][0] == ' ', v[0].length()) << " = " << a
              << delim;
    v.pop_front();
    deb(delim, std::move(v), args...);
}

template <typename... Args>
auto wrap(std::deque<std::string> v, Args... args) {
    auto f = [=](const char *delim = "\n") { deb(delim, v, args...); };

    return Debug<decltype(f)>(f);
}
}

#define debug(args...) ::detail::wrap(::detail::split(#args, ','), args)

#ifdef USING_BOOST

#include <boost/math/common_factor.hpp>
#include <boost/range.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/algorithm_ext.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/numeric.hpp>

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

#pragma endregion

/*** Template End ***/

int n;
vector<i64> x, c, v;
i64 memo[18][1 << 18];

i64 calc(i64 w, const vector<i64> &cost, const vector<i64> &value) {
    int m = cost.size();

    i64 maxi = 0;

    for (int i : rep(0, 1 << m)) {
        i64 csum = 0, vsum = 0;
        for (int j : rep(0, m)) {
            if (i >> j & 1) {
                csum += cost[j];
                vsum += value[j];
            }
        }

        if (csum <= w) {
            maxi = max(maxi, vsum);
        }
    }

    return maxi;
}

int64_t solve(int n, i64 w, const vector<i64> &a, const vector<i64> &b) {
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

i64 dfs(int i, int s) {
    if (i == n) {
        return 0;
    }

    if (memo[i][s] != -1) {
        return memo[i][s];
    }

    i64 ret = 1LL << 60;

    for (int k : rep(0, n)) {
        if (!(s >> k & 1)) {
            ret = min(ret, dfs(i + 1, s | (1 << k)));
        }
    }

    {
        vector<i64> cost, value;
        for (int k : rep(0, n)) {
            if (!(s >> k & 1)) {
                cost.push_back(c[k]);
                value.push_back(v[k]);
            }
        }

        // ret = max(ret, calc(x[i], cost, value));
        ret = max(ret, solve(value.size(), x[i], value, cost));
    }

    return memo[i][s] = ret;
}

int main() {
    in(n);

    x = vin<i64>(n);
    c = vin<i64>(n);
    v = vin<i64>(n);

    x.insert(x.begin(), 0LL);
    for (int i : rep(1, n)) {
        x[i] += x[i - 1];
    }

    fill((i64 *)memo, (i64 *)(memo + n), -1LL);

    out(dfs(0, 0));
}