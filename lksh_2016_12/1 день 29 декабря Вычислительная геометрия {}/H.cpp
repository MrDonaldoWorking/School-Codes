#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
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

ifstream in("intersec2.in");
ofstream out("intersec2.out");

const ld EPS = 1e-8;

struct Vector {
	int x, y;

	Vector(int x_arg = 0, int y_arg = 0) {
		x = x_arg;
		y = y_arg;
	}
};

inline int area(Vector a, Vector b, Vector c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline bool intersect_1(int a, int b, int c, int d) {
	if (a > b)  swap(a, b);
	if (c > d)  swap(c, d);
	return max(a, c) <= min(b, d);
}

bool intersect(Vector a, Vector b, Vector c, Vector d) {
	bool ans;
	ans = intersect_1(a.x, b.x, c.x, d.x);
	ans = ans && intersect_1(a.y, b.y, c.y, d.y);
	ans = ans && area(a, b, c) * area(a, b, d) <= 0;
	ans = ans && area(c, d, a) * area(c, d, b) <= 0;
	return ans;
}

int main() {
	Vector a, b, c, d;
	in >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

	if (intersect(a, b, c, d))
		out << "YES";
	else
		out << "NO";

	return 0;
}