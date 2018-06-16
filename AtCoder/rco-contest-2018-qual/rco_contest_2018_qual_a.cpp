/*** Template Begin ***/

#pragma region template

#define USING_BOOST
#define USING_NAMESPACE

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
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

int n, k, h, w, t;

const char direction[] = "UDLR";

int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};

mt19937 gen;
uniform_int_distribution<int> dist(0, 3);

string solve(vector<string> m, int r) {
    int x = -1, y = -1;

    for (int i : rep(0, h)) {
        for (int j : rep(0, w)) {
            if (m[i][j] == '@') {
                x = j;
                y = i;

                break;
            }
        }

        if (x != -1 && y != -1) {
            break;
        }
    }

    string move;

    for (int i : rep(0, r)) {
        int d;
        bool ok = false;
        for (int k : rep(0, 5)) {
            d = dist(gen);

            int nx = x + dx[d], ny = y + dy[d];

            if (m[ny][nx] == 'x' || m[ny][nx] == '#' || m[ny][nx] == '@') {
                continue;
            }

            ok = true;
            break;
        }

        if (!ok) {
            for (int k : rep(0, 100)) {
                d = dist(gen);

                int nx = x + dx[d], ny = y + dy[d];

                if (m[ny][nx] == 'x' || m[ny][nx] == '#') {
                    continue;
                }

                break;
            }
        }

        m[y][x] = '@';

        x = x + dx[d];
        y = y + dy[d];

        if (m[y][x] == '#') {
            x = x - dx[d];
            y = y - dy[d];
        }

        move.push_back(direction[d]);
    }

    return move;
}

string solve2(vector<string> m1, vector<string> m2, int r) {
    int x1 = -1, y1 = -1;
    int x2 = -1, y2 = -1;

    for (int i : rep(0, h)) {
        for (int j : rep(0, w)) {
            if (m1[i][j] == '@') {
                x1 = j;
                y1 = i;
            }

            if (m2[i][j] == '@') {
                x2 = j;
                y2 = i;
            }
        }
    }

    string move;

    for (int i : rep(0, r)) {
        int d;
        bool ok = false;
        for (int k : rep(0, 5)) {
            d = dist(gen);

            int nx1 = x1 + dx[d], ny1 = y1 + dy[d];
            int nx2 = x2 + dx[d], ny2 = y2 + dy[d];

            if (m1[ny1][nx1] == 'x' || m1[ny1][nx1] == '#' ||
                m1[ny1][nx1] == '@') {
                continue;
            }

            if (m2[ny2][nx2] == 'x' || m2[ny2][nx2] == '#' ||
                m2[ny2][nx2] == '@') {
                continue;
            }

            ok = true;
            break;
        }

        if (!ok) {
            for (int k : rep(0, 100)) {
                d = dist(gen);

                int nx1 = x1 + dx[d], ny1 = y1 + dy[d];
                int nx2 = x2 + dx[d], ny2 = y2 + dy[d];

                if (m1[ny1][nx1] == 'x') {
                    continue;
                }

                if (m2[ny2][nx2] == 'x') {
                    continue;
                }

                if (m1[ny1][nx1] == '#' && m2[ny2][nx2] == '#') {
                    continue;
                }

                break;
            }
        }

        m1[y1][x1] = '@';
        m2[y2][x2] = '@';

        x1 = x1 + dx[d];
        y1 = y1 + dy[d];

        if (m1[y1][x1] == '#') {
            x1 = x1 - dx[d];
            y1 = y1 - dy[d];
        }

        x2 = x2 + dx[d];
        y2 = y2 + dy[d];

        if (m2[y2][x2] == '#') {
            x2 = x2 - dx[d];
            y2 = y2 - dy[d];
        }

        move.push_back(direction[d]);
    }

    return move;
}

string solvek(vector<vector<string>> mm, int r) {
    int a = mm.size();

    vector<int> x(a, -1), y(a, -1);

    for (int i : rep(0, h)) {
        for (int j : rep(0, w)) {
            for (int k : rep(0, a)) {
                if (mm[k][i][j] == '@') {
                    x[k] = j;
                    y[k] = i;
                }
            }
        }
    }

    string move;

    for (int i : rep(0, r)) {
        int d;
        bool ok = false;
        for (int _ : rep(0, 5)) {
            d = dist(gen);

            vector<int> nx(a), ny(a);

            bool ng = false;

            for (int k : rep(0, a)) {
                nx[k] = x[k] + dx[d];
                ny[k] = y[k] + dy[d];

                if (mm[k][ny[k]][nx[k]] == 'x' || mm[k][ny[k]][nx[k]] == '#' ||
                    mm[k][ny[k]][nx[k]] == '@') {
                    ng = true;
                    break;
                }
            }

            if (ng) {
                continue;
            }

            ok = true;
            break;
        }

        if (!ok) {
            for (int _ : rep(0, 100)) {
                d = dist(gen);

                vector<int> nx(a), ny(a);

                bool ng = false;

                for (int k : rep(0, a)) {
                    nx[k] = x[k] + dx[d];
                    ny[k] = y[k] + dy[d];

                    if (mm[k][ny[k]][nx[k]] == 'x') {
                        ng = true;
                        break;
                    }
                }

                if (ng) {
                    continue;
                }

                break;
            }
        }

        for (int k : rep(0, a)) {
            mm[k][y[k]][x[k]] = '@';

            x[k] = x[k] + dx[d];
            y[k] = y[k] + dy[d];

            if (mm[k][y[k]][x[k]] == '#') {
                x[k] = x[k] - dx[d];
                y[k] = y[k] - dy[d];
            }
        }

        move.push_back(direction[d]);
    }

    return move;
}

int play(vector<string> m, string move) {
    int score = 0;

    int x = -1, y = -1;

    for (int i : rep(0, h)) {
        for (int j : rep(0, w)) {
            if (m[i][j] == '@') {
                x = j;
                y = i;

                break;
            }
        }

        if (x != -1 && y != -1) {
            break;
        }
    }

    for (int i : rep(0, move.size())) {
        int nx = x, ny = y;

        if (move[i] == 'U') {
            ny--;
        } else if (move[i] == 'D') {
            ny++;
        } else if (move[i] == 'L') {
            nx--;
        } else if (move[i] == 'R') {
            nx++;
        } else {
            cerr << "Error" << endl;
        }

        if (m[ny][nx] == '#') {
            nx = x;
            ny = y;
        } else if (m[ny][nx] == 'x') {
            return score;
        } else if (m[ny][nx] == 'o') {
            score++;
            m[ny][nx] = '@';
        }

        x = nx;
        y = ny;
    }

    return score;
}

int main() {
    in(n, k, h, w, t);

    multi_vector<string, 2> maps(n);

    for (int i : rep(0, n)) {
        maps[i] = vin<string>(h);
    }

    string move;
    vector<int> select;
    int max_score = 0;

    const int mm_size = 8;

    vector<pair<int, int>> num_traps(n);

    for (int i : rep(0, n)) {
        num_traps[i].second = i;
        for (int j : rep(0, h)) {
            num_traps[i].first += count(maps[i][j], 'x');
        }
    }

    sort(num_traps);

    for (int _ : rep(0, n)) {
        multi_vector<string, 2> mm(mm_size);

        for (int k : rep(0, mm_size)) {
            mm[k] = maps[num_traps[k].second];
        }

        string cur_move = solvek(mm, t);

        vector<pair<int, int>> scores(n);

        for (int i : rep(0, n)) {
            scores[i].first = play(maps[i], cur_move);
            scores[i].second = i;
        }

        sort(scores, greater<>());

        vector<int> cur_select;

        int score = 0;

        for (int i : rep(0, k)) {
            cur_select.push_back(scores[i].second);

            score += scores[i].first;
        }

        if (score > max_score) {
            move = cur_move;
            select = cur_select;
            max_score = score;
        }
    }
    vout(select, k);

    out(move);
}