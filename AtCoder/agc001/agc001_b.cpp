#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iomanip>

using namespace std;

typedef long long ll;

ll calc(ll a, ll b)
{
	return b == 0 ? 0 : calc(b, a % b) + b * (a / b);
}

int main()
{
	ll n, x;
	cin >> n >> x;

	cout << 3 * calc(n - x, x) << endl;
}