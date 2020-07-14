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

ifstream in("distance2.in");
ofstream out("distance2.out");

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
	ld x1, y1, x2, y2, x0, y0;
	in >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;

	ld A = y1 - y2, B = x2 - x1, C = x1 * y2 - y1 * x2;

	out.precision(12);
	out << fixed;
	out << abs(A * x0 + B * y0 + C) / sqrt(A * A + B * B);

	return 0;
}