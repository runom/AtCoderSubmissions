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

vector<vector<int>> g;
vector<int> dep;
vector<int> par;

void depth(int id, int d) {
    dep[id] = d;
    for (int to : g[id]) {
        if (dep[to] != -1) continue;
        depth(to, d + 1);
    }
}

void parent(int id, int p) {
    par[id] = p;
    for (int to : g[id]) {
        if (to == p) continue;
        parent(to, id);
    }
}

vector<int> lowest_common_ancestor(const vector<vector<int>> &graph,
                                   const vector<pair<int, int>> &query) {
    int n = graph.size();
    vector<vector<int>> kparent(30, vector<int>(n, -1));

    par = vector<int>(n, -1);
    parent(0, -1);
    kparent[0] = par;

    for (int k = 1; (1 << k) < n; k++) {
        for (int i : rep(0, n)) {
            if (kparent[k - 1][i] == -1) {
                kparent[k][i] = -1;
            } else {
                kparent[k][i] = kparent[k - 1][kparent[k - 1][i]];
            }
        }
    }

    vector<int> res;
    for (auto &&q : query) {
        int u, v;
        tie(u, v) = q;

        if (dep[u] > dep[v]) {
            swap(u, v);
        }

        int d = dep[v] - dep[u];

        for (int k : rep(0, 30)) {
            if (d & (1 << k)) {
                v = kparent[k][v];
            }
        }

        for (int k : rep(0, 30) | reversed) {
            if (kparent[k][u] != kparent[k][v]) {
                u = kparent[k][u];
                v = kparent[k][v];
            }
        }

        while (u != v) {
            u = par[u];
            v = par[v];
        }

        res.push_back(u);
    }

    return res;
}

int main() {
    int n;
    in(n);

    g = vector<vector<int>>(n);
    for (int i : rep(0, n - 1)) {
        int x, y;
        in(x, y);
        x--;
        y--;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    dep = vector<int>(n, -1);
    depth(0, 0);

    int q;
    in(q);
    vector<pair<int, int>> query;
    for (int i : rep(0, q)) {
        int u, v;
        in(u, v);
        u--;
        v--;
        query.emplace_back(u, v);
    }

    auto lca = lowest_common_ancestor(g, query);

    for (int i : rep(0, q)) {
        int u, v;
        tie(u, v) = query[i];

        out(dep[u] - dep[lca[i]] + dep[v] - dep[lca[i]] + 1);
    }
}