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

// memory: O(Q loglogN logN)
// mutable_get: O(loglogN logN)
// immutable_get: O(loglogN)
class Array {
   public:
    Array() {}

    Array(int n) {
        h = 0;
        for (int i = 1; i < n; i *= 8) h += 3;
    }

    int *mutable_get(int k) {
        auto p = mutable_get(k, root, 0, h);
        root = p.first;
        return &p.second->value;
    }

    int operator[](int k) {
        node *res = immutable_get(k, root, 0, h);
        return res != nullptr ? res->value : -1;
    }

   private:
    struct node {
        node *ch[8] = {};
        int value = -1;
    };

    int h;
    node *root = nullptr;

    node *immutable_get(int a, node *x, int l, int d) {
        if (x == nullptr) return x;
        if (d == 0) return x;
        int id = (a - l) >> (d - 3);
        return immutable_get(a, x->ch[id], l + (id << (d - 3)), d - 3);
    }

    pair<node *, node *> mutable_get(int a, node *x, int l, int d) {
        x = x != nullptr ? new node(*x) : new node();
        if (d == 0) return make_pair(x, x);
        int id = (a - l) >> (d - 3);
        auto p = mutable_get(a, x->ch[id], l + (id << (d - 3)), d - 3);
        x->ch[id] = p.first;
        return make_pair(x, p.second);
    }
};

// root: O(logN loglogN)
// merge: O(logN loglogN)
struct UnionFind {
    Array uf;

    UnionFind() : uf(0) {}

    UnionFind(int n) : uf(n) {}

    int root(int x) {
        int nd = uf[x];
        if (nd < 0) return x;
        return root(nd);
    }

    void merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;

        int *u = uf.mutable_get(x);
        int *v = uf.mutable_get(y);
        if (-*u < -*v) swap(u, v), swap(x, y);

        *u += *v;
        *v = x;
    }

    int size(int x) { return -uf[root(x)]; }

    int query(int x, int y) {
        x = root(x);
        y = root(y);
        return x == y;
    }
};

int main() {
    int n, m;
    in(n, m);

    UnionFind uf(n);
    vector<UnionFind> ufs(m + 1);

    ufs[0] = uf;

    for (int i : rep(0, m)) {
        int a, b;
        in(a, b);
        a--;
        b--;

        uf.merge(a, b);
        ufs[i + 1] = uf;
    }

    int q;
    in(q);

    for (int i : rep(0, q)) {
        int x, y;
        in(x, y);
        x--;
        y--;
        if (!ufs[m].query(x, y)) {
            out(-1);
            continue;
        }

        int l = 0, r = m;

        while (r - l > 1) {
            int mid = (l + r) / 2;

            if (ufs[mid].query(x, y)) {
                r = mid;
            } else {
                l = mid;
            }
        }

        out(r);
    }
}