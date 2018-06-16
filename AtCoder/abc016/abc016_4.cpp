#include <iostream>
#include <complex>
#include <vector>
using namespace std;

const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> P;
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}

struct L : public vector<P> {
  L(const P &a, const P &b) {
    push_back(a); push_back(b);
  }
};

typedef vector<P> G;

struct C {
  P p; double r;
  C(const P &p, double r) : p(p), r(r) { }
};

int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;
}

bool intersectSS(const L &s, const L &t) {
  return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
         ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}


int main() {
	int Ax, Ay, Bx, By;
	cin >> Ax >> Ay >> Bx >> By;
	
	L l(P(Ax, Ay), P(Bx, By));
	
	int N;
	cin >> N;
	
	vector<P> ps;
	
	for(int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		ps.emplace_back(x, y);
	}
	
	
	int cnt = 0;
	
	for(int i = 0; i < ps.size(); ++i) {
		if(intersectSS(l, L(ps[i], ps[(i + 1) % ps.size()]))) cnt++;
	}
	
	cout << cnt / 2 + 1<< endl;
	return 0;
}
