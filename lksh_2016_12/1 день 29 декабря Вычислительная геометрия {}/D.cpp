#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

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

ifstream in("intersec1.in");
ofstream out("intersec1.out");

ld scal_ld(ld x1, ld y1, ld x2, ld y2) {
	return x1 * x2 + y1 * y2;
}

ld vec_ld(ld x1, ld y1, ld x2, ld y2) {
	return x1 * y2 - x2 * y1;
}

int scal_int(int x1, int y1, int x2, int y2) {
	return x1 * x2 + y1 * y2;
}

int vec_int(int x1, int y1, int x2, int y2) {
	return x1 * y2 - x2 * y1;
}

int main() {
	ld a, b, c, a1, b1, c1;
	in >> a >> b >> c >> a1 >> b1 >> c1;

	ld x, y;
	y = (c * a1 - a * c1) / (b1 * a - b * a1);
	x = (b * c1 - c * b1) / (b1 * a - b * a1);

	out.precision(12);
	out << fixed;
	out << x << ' ' << y;

	return 0;
}