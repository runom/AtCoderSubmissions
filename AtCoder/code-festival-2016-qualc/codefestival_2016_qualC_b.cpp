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

using namespace std;

#ifdef __has_include
  #if __has_include(<boost/version.hpp>)
    #include <boost/range.hpp>
    #include <boost/range/irange.hpp>
    #include <boost/range/adaptors.hpp>
    #include <boost/range/algorithm.hpp>
    #include <boost/range/algorithm_ext.hpp>
    using namespace boost;
    using namespace boost::adaptors;
  #endif
#endif

auto init_ = []{
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

template <typename T, typename U = std::vector<T>>
inline U in(int n) {
    U v(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    return v;
}

template <typename T, typename U = std::vector<T>, typename V = std::vector<U>>
inline V in(int h, int w) {
    V vv(h, U(w));
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j) {
            std::cin >> vv[i][j];
        }
    }
   return vv;
}

template <typename T>
inline void out(const T& x) {
	std::cout << x << std::endl;
}

template <char delimiter = ' ', typename T, typename... Ts>
inline void out(const T& t, const Ts&... ts) {
	std::cout << t << delimiter;
	out(ts...);
}

template <char delimiter = ' ', typename T>
inline void vout(const T& v, int n) {
	for(int i = 0; i < n; ++i) {
		if(i) std::cout << delimiter;
		std::cout << v[i];
	}
	std::cout << std::endl;
}


int main() {
    auto k = in<int>();
    auto t = in<int>();
    auto a = in<int>(t);

    vector<pair<int, int>> v;
    for(int i = 0; i < a.size(); ++i) {
        v.emplace_back(a[i], i);
    }

    if(t == 1) {
        out(a[0] - 1);
    } else {
        int ans = 0;
        int pr = -1;
    
        priority_queue<pair<int, int>> que(v.begin(), v.end());

        while(que.size() > 1) {
            auto x = que.top(); que.pop();
            auto y = que.top(); que.pop();

            if(x.second == pr) {
                ans++;
            }

            pr = x.second;

            x.first--;

            if(x.first != 0) {
                que.push(x);
            }

            if(y.second == pr) {
                ans++;
            }

            pr = y.second;

            y.first--;

            if(y.first != 0) {
                que.push(y);
            }
        }

        if(que.size() == 1) {
            auto x = que.top();

            if(x.second == pr) {
                ans += x.first;
            } else {
                ans += x.first - 1;
            }
        }

        out(ans);
    } 
}