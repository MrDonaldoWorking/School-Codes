#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
typedef long long ll;
typedef unsigned long long ull;
#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
#define fi first
#define se second
using namespace std;

vector<pair<ll, ll>> a;

bool comp(const pair <ll, ll> &a, const pair <ll, ll> &b) {
	return a.fi < b.fi;
}

int main() {
	//ifstream in("reverse.in");
	//ofstream out("reverse.out");
	ll n, q;
	cin >> n;
	a.resize(n);
	forn(i, 0, n)
		cin >> a[i].fi >> a[i].se;
	stable_sort(a.begin(), a.end(), comp);
	forn(i, 0, n)
		cout << a[i].fi << ' ' << a[i].se << endl;
	return 0;
}