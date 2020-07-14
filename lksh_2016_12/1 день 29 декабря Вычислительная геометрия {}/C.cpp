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

ifstream in("line1.in");
ofstream out("line1.out");

ld scal(ld x1, ld y1, ld x2, ld y2) {
	return x1 * x2 + y1 * y2;
}

ld vec(ld x1, ld y1, ld x2, ld y2) {
	return x1 * y2 - x2 * y1;
}

int main() {
	ld x1, x2, y1, y2;
	in >> x1 >> y1 >> x2 >> y2;

	out.precision(12);
	out << fixed;
	out << y1 - y2 << ' ' << x2 - x1 << ' ' << vec(x1, y1, x2, y2);

	return 0;
}