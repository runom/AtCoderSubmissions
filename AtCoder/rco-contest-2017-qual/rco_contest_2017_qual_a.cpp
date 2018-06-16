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

const int H = 50;
const int W = 50;
const int K = 8;

vector<vector<int>> grid;

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

struct Piece {
    vector<int> xs, ys;
    vector<int> ss;
    int score = 0;
};

vector<Piece> solve() {
    vector<Piece> ans;

    for (int i : rep(0, H / 3)) {
        for (int j : rep(0, W / 3)) {
            Piece piece;
            for (int y = i * 3; y < i * 3 + 3; ++y) {
                for (int x = j * 3; x < j * 3 + 3; ++x) {
                    piece.xs.push_back(x);
                    piece.ys.push_back(y);
                    piece.ss.push_back(grid[y][x]);
                }
            }

            auto idx = min_element(piece.ss) - piece.ss.begin();

            piece.xs.erase(piece.xs.begin() + idx);
            piece.ys.erase(piece.ys.begin() + idx);
            piece.ss.erase(piece.ss.begin() + idx);

            piece.score = accumulate(piece.ss, 0);

            ans.push_back(piece);
        }
    }

    return ans;
}

vector<Piece> solve2() {
    vector<Piece> ans;

    vector<vector<bool>> used(H, vector<bool>(W));

    mt19937 gen(rand());
    uniform_int_distribution<int> dist(0, H - 1);
    auto rand = [&] { return dist(gen); };

    int failcount = 0;

    while (true) {
        int x = rand();
        int y = rand();

        {
            int failcount = 0;
            int th = 7;
            while (grid[y][x] < th || used[y][x]) {
                x = rand();
                y = rand();
                failcount++;

                if (failcount == 50) {
                    th--;
                    failcount = 0;
                }
            }
        }

        int cnt = 1;

        vector<int> xs, ys, ss;
        xs.push_back(x);
        ys.push_back(y);
        ss.push_back(grid[y][x]);

        int th = 9;
        used[y][x] = true;

        while (cnt < 8) {
            priority_queue<std::tuple<int, int, int>> que;

            for (int i : rep(0, cnt)) {
                int x = xs[i];
                int y = ys[i];

                for (int k : rep(0, 4)) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (0 <= nx && nx < W && 0 <= ny && ny < H &&
                        !used[ny][nx] && grid[ny][nx] >= 1) {
                        que.emplace(grid[ny][nx], ny, nx);
                    }
                }
            }

            if (que.empty()) {
                th--;
                if (th == 0) {
                    break;
                }
                continue;
            }

            th = 9;

            int addX, addY, score;
            std::tie(score, addY, addX) = que.top();

            xs.push_back(addX);
            ys.push_back(addY);
            ss.push_back(score);
            used[addY][addX] = true;

            cnt++;
        }

        if (cnt != 8) {
            failcount++;

            if (failcount > 50) {
                break;
            }

            continue;
        }

        failcount = 0;
        Piece piece;
        piece.xs = xs;
        piece.ys = ys;
        piece.ss = ss;

        ans.push_back(piece);
    }
    return ans;
}

int main() {
    int h, w, k;
    in(h, w, k);

    assert(h == H && w == W && k == K);

    vector<string> in;

    in = vin<string>(h);

    grid = vector<vector<int>>(h, vector<int>(w));

    for (int i : rep(0, H)) {
        assert(in[i].size() == W);
        for (int j : rep(0, W)) {
            grid[i][j] = in[i][j] - '0';
        }
    }

    int maxi = 0;
    vector<Piece> answer;

    for (int i = 0; i < 1000; ++i) {
        auto cur_answer = solve2();

        int sum = 0;
        for (auto &piece : cur_answer) {
            int pr = 1;
            for (int i : rep(0, K)) {
                pr *= piece.ss[i];
            }
            sum += pr;
        }

        if (sum > maxi) {
            maxi = sum;
            answer = cur_answer;
        }
    }

    out(answer.size());

    for (auto &piece : answer) {
        assert(piece.xs.size() == K && piece.ys.size() == K);
        for (int i : rep(0, K)) {
            out(piece.ys[i] + 1, piece.xs[i] + 1);
        }
    }
}