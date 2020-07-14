#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
typedef long long ll;
#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
using namespace std;

int t = 0;
vector<ll> a;

bool search(ll x) {
	ll l = 0, r = a.size(), m;
	while (r - l > 1) {
		m = (l + r) / 2;
		if (a[m] > x) r = m;
		else l = m;
	}
	if (a[l] == x) return true;
	return false;
}

int main() {
	//ifstream in("reverse.in");
	//ofstream out("reverse.out");
	int n, m;
	ll t;
	cin >> n;
	a = vector<ll>(n);
	forn(i, 0, n) cin >> a[i];
	cin >> m;
	a.push_back(2000000001);
	forn(i, 0, m) {
		cin >> t;
		if (search(t)) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	return 0;
}