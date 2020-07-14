#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
typedef unsigned long long ull;
typedef long long ll;
#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
using namespace std;

vector<ll> a;

int f(ll x) {
	ll s = 0;
	forn(i, 0, a.size())
		s += a[i] / x;
	return s;
}

ll search(ll x) {
	ll l = 0, r = 1000000001, m;
	while (r - l > 1) {
		m = (l + r) / 2;
		if (f(m) >= x)
			l = m;
		else 
			r = m;
	}
	return l;
}

int main() {
	//ifstream in("reverse.in");
	//ofstream out("reverse.out");
	int n, k;
	cin >> n >> k;
	a = vector<ll>(n);
	forn(i, 0, n)
		cin >> a[i];
	cout << search(k);
	return 0;
}