#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
#define sz(a) (int)a.size()
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ifstream in("triangle.in");
ofstream out("triangle.out");


ll fi(ll n) {
	ll m = n;
	map<ll, ll> a;

	for (ll i = 2; i * i <= m; i++) {
		while (n % i == 0) {
			a[i]++;
			n /= i;
		}
	}

	if (n > 1) {
		a[n]++;
	}

	ll ans = 1;
	for (auto i : a) {
		ll power = 1;
		forn(j, 0, i.second)
			power *= i.first;

		ans *= power - power / i.first;
	}

	return ans;
}

int main() {
	ll n;
	in >> n;
	//if (n % 2 == 0)
		//out << 0;

	n = (n + 1) / 2 + 1;
	out << fi(n);

	int a, b;
	a = 5; b = 3;
	cout << "a,=Z(" << b << ")";

	return 0;
}