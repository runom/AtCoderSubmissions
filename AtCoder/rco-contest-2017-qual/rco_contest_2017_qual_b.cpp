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
#include <random>
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

#define debug(args...) detail::wrap(detail::split(#args, ','), args)

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

const int H = 50, W = 50, K = 2500;

int sr, sc;

int N;

vector<string> grid;
vector<int> Fs, Ds;

vector<std::tuple<int, int, int, int>> FDs;

const int inf = 1 << 26;

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
const char mov[] = "DRUL";

int cost[H][W][H][W];
int prev[H][W][H][W];

void bfs(int ax, int ay) {
    cost[ay][ax][ay][ax] = 0;

    queue<pair<int, int>> que;
    que.emplace(ay, ax);

    while (!que.empty()) {
        auto p = que.front();
        que.pop();

        int x = p.second, y = p.first;

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];

            if (0 <= nx && nx < W && 0 <= ny && ny < H && grid[ny][nx] != '#' &&
                cost[ay][ax][ny][nx] == inf) {
                cost[ay][ax][ny][nx] = cost[ay][ax][y][x] + 1;
                ::prev[ay][ax][ny][nx] = k;

                que.emplace(ny, nx);
            }
        }
    }
}

string solve() {
    string ans;

    int x = sc, y = sr;

    vector<bool> used(N);

    int n = N;

    while (n > 0 && ans.size() < K) {
        int maxi = -inf;
        int idx = -1;
        for (int i : rep(0, N)) {
            if (used[i]) {
                continue;
            }

            int fr = get<0>(FDs[i]), fc = get<1>(FDs[i]);
            int d = cost[y][x][fr][fc];

            if (get<2>(FDs[i]) - get<3>(FDs[i]) * (d + (int)ans.size()) < 0) {
                continue;
            }

            int val = -(d + ans.size());

            if (val > maxi) {
                maxi = val;
                idx = i;
            }
        }

        if (idx == -1) {
            break;
        }

        string res;

        int fr = get<0>(FDs[idx]), fc = get<1>(FDs[idx]);
        int nx = fc, ny = fr;

        int k = ::prev[y][x][fr][fc];

        while (fr != y || fc != x) {
            int k = ::prev[y][x][fr][fc];

            res += mov[k];

            fr = fr + dy[(k + 2) % 4];
            fc = fc + dx[(k + 2) % 4];
        }

        x = nx;
        y = ny;

        used[idx] = true;

        reverse(res.begin(), res.end());

        ans += res;

        n--;
    }

    ans.resize(K, '-');

    return ans;
}

int main() {
    int h, w, k;
    in(h, w, k, sr, sc);

    sr--;
    sc--;

    grid = vin<string>(H);

    in(N);

    for (int i : rep(0, N)) {
        int fr, fc, f, d;
        in(fr, fc, f, d);
        fr--;
        fc--;
        FDs.emplace_back(fr, fc, f, d);
    }

    fill((int *)cost, (int *)(cost + H), inf);

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            bfs(j, i);
        }
    }

    string ans = solve();

    assert(ans.size() == K);

    out(ans);
}