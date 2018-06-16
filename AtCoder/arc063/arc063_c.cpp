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

/*** Template End ***/

using Range = pair<int, int>;

int n;
vector<vector<int>> tree;
vector<Range> ranges;
vector<int> ps;

const int inf = 1 << 28;

pair<bool, Range> merge(Range a, Range b) {
    if (a > b) {
        swap(a, b);
    }

    if (a.first == -inf) {
        return {true, b};
    }

    if (b.first == -inf) {
        return {true, a};
    }

    if (a.second < b.first) {
        return {false, {}};
    }

    if ((a.first ^ b.first) & 1) {
        return {false, {}};
    }

    Range r(max(a.first, b.first), min(a.second, b.second));

    return {true, r};
}

Range dfs(int node, int par) {
    Range r = ranges[node];

    for (int to : tree[node]) {
        if (to == par) {
            continue;
        }

        auto rc = dfs(to, node);

        if (rc.first != -inf) {
            rc.first--;
        }

        if (rc.second != inf) {
            rc.second++;
        }

        auto merged = merge(r, rc);

        if (!merged.first) {
            out("No");
            exit(0);
        }

        r = merged.second;
    }
    return ranges[node] = r;
}

void setValue(int node, int par, int p) {
    if (ps[node] == -1) {
        if (par == -1) {
            ps[node] = ranges[node].first;
        } else {
            if (ranges[node].first <= p + 1 && p + 1 <= ranges[node].second) {
                ps[node] = p + 1;
            } else {
                ps[node] = p - 1;
            }
        }
    }

    for (int to : tree[node]) {
        if (to == par) {
            continue;
        }

        setValue(to, node, ps[node]);
    }
}

int main() {
    in(n);

    tree.assign(n, {});
    ps.assign(n, -1);
    ranges.assign(n, {-inf, inf});

    for (int i : rep(0, n - 1)) {
        int a, b;
        in(a, b);

        a--;
        b--;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int k;
    in(k);

    for (int i : rep(0, k)) {
        int v, p;
        in(v, p);

        v--;

        ps[v] = p;
        ranges[v].first = ranges[v].second = p;
    }

    auto r = dfs(0, -1);

    setValue(0, -1, -1);

    out("Yes");

    for (int i : rep(0, n)) {
        out(ps[i]);
    }
}