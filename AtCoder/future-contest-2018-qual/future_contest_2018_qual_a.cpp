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

#include <random>
#include <chrono>

const int n = 100;

using Squares = array<array<int, n>, n>;

Squares A;

struct S {
    int x, y, h;
};

using Answer = vector<S>;

mt19937 gen(random_device{}());
//mt19937 gen;
uniform_int_distribution<int> dist(0, n - 1);

Answer get_random_solution() {
    Answer res(1000);

    for(int i : rep(0, 1000)) {
        res[i].x = dist(gen);
        res[i].y = dist(gen);
        res[i].h = dist(gen) + 1;
    }

    return res;
}

void modify_squares(Squares& B, int x, int y, int h, int sign = 1) {
    B[y][x] += sign * h;

    for(int i : rep(1, h)) {
        
        if(x + i < n) {
            B[y][x + i] += sign * (h - i);
        }

        if(x - i >= 0) {
            B[y][x - i] += sign * (h - i);
        }

        if(y + i < n) {
            B[y + i][x] += sign * (h - i);
        }

        if(y - i >= 0) {
            B[y - i][x] += sign * (h - i);
        }

        for(int j : rep(1, i)) {
            if(y + j < n && x + i - j < n) {
                B[y + j][x + i - j] += sign * (h - i);
            }

            if(y - j >= 0 && x + i - j < n) {
                B[y - j][x + i - j] += sign * (h - i);
            }

            if(y + j < n && x - i + j >= 0) {
                B[y + j][x - i + j] += sign * (h - i);
            }

            if(y - j >= 0 && x - i + j >= 0) {
                B[y - j][x - i + j] += sign * (h - i);
            }
        }
    }
}

Squares get_squares(const Answer& answer) {
    Squares B = {};
    
    for(S s : answer) {
        int x = s.x, y = s.y, h = s.h;

        modify_squares(B, x, y, h);
    }

    return B;
}

int calc_score(const Squares& B) {
    int sum = 0;

    for(int i : rep(0, n)) {
        for(int j : rep(0, n)) {
            sum += abs(A[i][j] - B[i][j]);
        }
    }

    return sum;
}

auto pow2 = [](int x) {
    return x * x;
};

i64 calc_score_square(const Squares& B) {
    i64 sum = 0;

    for(int i : rep(0, n)) {
        for(int j : rep(0, n)) {
            sum += (A[i][j] - B[i][j]) * (A[i][j] - B[i][j]);
        }
    }

    return sum;
}

i64 calc_partial_score(Squares& B, int x, int y, int h) {
    
    i64 score = 0;

    score += pow2(A[y][x] - B[y][x]);

    for(int i : rep(1, h)) {
        
        if(x + i < n) {
            score += pow2(A[y][x + i] - B[y][x + i]);
        }

        if(x - i >= 0) {
            score += pow2(A[y][x - i] - B[y][x - i]);
        }

        if(y + i < n) {
            score += pow2(A[y + i][x] - B[y + i][x]);
        }

        if(y - i >= 0) {
            score += pow2(A[y - i][x] - B[y - i][x]);
        }

        for(int j : rep(1, i)) {
            if(y + j < n && x + i - j < n) {
                score += pow2(A[y + j][x + i - j] - B[y + j][x + i - j]);
            }

            if(y - j >= 0 && x + i - j < n) {
                score += pow2(A[y - j][x + i - j] - B[y - j][x + i - j]);
            }

            if(y + j < n && x - i + j >= 0) {
                score += pow2(A[y + j][x - i + j] - B[y + j][x - i + j]);
            }

            if(y - j >= 0 && x - i + j >= 0) {
                score += pow2(A[y - j][x - i + j] - B[y - j][x - i + j]);
            }
        }
    }

    return score;
}

int main() {

    using namespace chrono;

    auto program_start_time = system_clock::now();

    for(int i : rep(0, n)){
        for(int j : rep(0, n)) {
            cin >> A[i][j];
        }
    }

    auto answer = get_random_solution();
    auto squares = get_squares(answer);
    auto score = calc_score_square(squares);

    int cnt = 0;
    int fail_cnt = 0;

    while(true) {

        auto current_time = system_clock::now();

        if(duration_cast<milliseconds>(current_time - program_start_time).count() > 5950) {
           break;
        }

        uniform_int_distribution<int> select(0, answer.size() - 1);

        int selected_index = select(gen);

        S& s = answer[selected_index];

        auto bs1 = calc_partial_score(squares, s.x, s.y, s.h);
        modify_squares(squares, s.x, s.y, s.h, -1);
        auto as1 = calc_partial_score(squares, s.x, s.y, s.h);

        auto d = as1 - bs1;

        const int dx[] = {0, 1, -1, 0, 0}, dy[] = {0, 0, 0, 1, -1};
        int r = rand() % 5;
        int x = max(0, min(n - 1, s.x + dx[r])), y = max(0, min(n - 1, s.y + dy[r]));

        auto current_score = score + d;

        int h1 = max(1, s.h - 1);
        int h2 = min(100, s.h + 1);

        auto bs21 = calc_partial_score(squares, x, y, h1);
        modify_squares(squares, x, y, h1, 1);
        auto as21 = calc_partial_score(squares, x, y, h1);
        modify_squares(squares, x, y, h1, -1);
        auto d1 = as21 - bs21;

        auto bs22 = calc_partial_score(squares, x, y, h2);
        modify_squares(squares, x, y, h2, 1);
        auto as22 = calc_partial_score(squares, x, y, h2);
        modify_squares(squares, x, y, h2, -1);
        auto d2 = as22 - bs22;

        if(d1 + d > 0 && d2 + d > 0) {
            modify_squares(squares, s.x, s.y, s.h, +1);
        } else if(d1 < d2) {
            score = current_score + d1;
            s.x = x;
            s.y = y;
            s.h = h1;

            modify_squares(squares, x, y, h1, 1);
        } else {
            score = current_score + d2;
            s.x = x;
            s.y = y;
            s.h = h2;

            modify_squares(squares, x, y, h2, 1);
        }
    }

    out(answer.size());

    for(S x : answer) {
        out(x.x, x.y, x.h);
    }
}
