#include <iostream>
#include <algorithm>
using namespace std;

using Int = long long;

Int gcd(Int a, Int b) {
  return b != 0 ? gcd(b, a % b) : a;
}
Int lcm(Int a, Int b) {
  return a * b / gcd(a, b);
}
// a x + b y = gcd(a, b)
Int extgcd(Int a, Int b, Int &x, Int &y) {
  Int g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}

const Int Mod = 1'000'000'007;

Int comb(Int n, Int k)
{

	vector<Int> inv(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; ++i)
        inv[i] = inv[Mod % i] * (Mod - Mod / i) % Mod;
    
	Int a = 1.0;
	
	for(int i = 0; i < k; ++i) {
		a = a * (n - i) % Mod;
		a = a * inv[k - i] % Mod;
	}
	
	return a;
}

int main() {
	int w, h;
	cin >> w >> h;
	w--;
	h--;
	
	cout << comb(w + h, min(w, h)) << endl;
	
	return 0;
}