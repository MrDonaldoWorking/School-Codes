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

struct q {
	string n;
	int h;
	int w;
	bool operator < (const q &p) {
		if (w == p.w && h == p.h)
			return n < p.n;
		if (h == p.h)
			return w < p.w;
		return h < p.h;
	}
};

vector<q> a;
const int HEIGHT = 180, WEIGHT = 75;

int main() {
	//ifstream in("reverse.in");
	//ofstream out("reverse.out");
	int n;
	cin >> n;
	a.resize(n);
	forn(i, 0, n) {
		cin >> a[i].n;
		cin >> a[i].h;
		a[i].h = HEIGHT + abs(a[i].h - HEIGHT);
		cin >> a[i].w;
		if (a[i].w <= WEIGHT)
			a[i].w = -a[i].w;
	}
	sort(a.begin(), a.end());
	forn(i, 0, n)
		cout << a[i].n << endl;
	//cout << a[i].n << ' ' << a[i].h << ' ' << a[i].w << endl;
	return 0;
}