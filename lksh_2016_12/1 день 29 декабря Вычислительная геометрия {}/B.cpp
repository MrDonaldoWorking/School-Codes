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

ifstream in("angle2.in");
ofstream out("angle2.out");

ld scal(int x1, int y1, int x2, int y2) {
	return x1 * x2 + y1 * y2;
}

ld vec(int x1, int y1, int x2, int y2) {
	return x1 * y2 - x2 * y1;
}

int main() {
	int x1, x2, y1, y2;
	in >> x1 >> y1 >> x2 >> y2;

	out.precision(12);
	out << fixed;
	out << abs(atan2(vec(x1, y1, x2, y2), scal(x1, y1, x2, y2)));

	return 0;
}s