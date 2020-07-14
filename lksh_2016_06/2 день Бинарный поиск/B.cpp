#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
typedef long long ll;
#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
using namespace std;

vector<int> a;

int search1(ll x) {
	ll l = 0, r = a.size(), m;
	while (r - l > 1) {
		m = (l + r) / 2;
		if (a[m] > x)
			r = m;
		else 
			l = m;
	}
	if (a[l] == x) return r;
	else return 0;
}

int search2(int x) {
	ll l = 0, r = a.size(), m;
	while (r - l > 1) {
		m = (l + r) / 2;
		if (a[m] < x)
			l = m;
		else 
			r = m;
	}
	if (a[r] == x) return r;
	else return 0;
}

int main() {
	//ifstream in("reverse.in");
	//ofstream out("reverse.out");
	int n, m, t;
	cin >> n;
	a = vector<int>(n + 1);
	a[0] = -1;
	forn(i, 0, n)
		cin >> a[i + 1];
	a.push_back(1000000002);
	cin >> m;
	forn(i, 0, m) {
		cin >> t;
		cout << search1(t) - search2(t) << endl;
	}
	return 0;
}