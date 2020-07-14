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

ifstream in("bisector.in");
ofstream out("bisector.out");

struct Vector {
	ld x, y;

	Vector(ld x_arg = 0, ld y_arg = 0) {
		x = x_arg;
		y = y_arg;
	}
};

Vector operator -(const Vector &u) {
	return Vector(-u.x, -u.y);
}

Vector operator +(const Vector &u, const Vector &v) {
	return Vector(u.x + v.x, u.y + v.y);
}

Vector operator -(const Vector &u, const Vector &v) {
	return Vector(u.x - v.x, u.y - v.y);
}

Vector operator *(const Vector &u, ld k) {
	return Vector(k * u.x, k * u.y);
}

Vector operator *(ld k, const Vector &u) {
	return Vector(k * u.x, k * u.y);
}

ld scal(Vector v1, Vector v2) {
	return v1.x * v2.x + v1.y * v2.y;
}

ld vec(Vector v1, Vector v2) {
	return v1.x * v2.y - v2.x * v1.y;
}

ld length(Vector v1, Vector v2) {
	return sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
}

int main() {
	Vector va, vb, vc;
	in >> va.x >> va.y >> vb.x >> vb.y >> vc.x >> vc.y;

	ld ab, bc, ac;
	ab = length(va, vb);
	bc = length(vb, vc);
	ac = length(va, vc);

	ld a, b, c;
	a = (vb.y - va.y) / ab + (vc.y - va.y) / ac;
	b = (va.x - vb.x) / ab + (va.x - vc.x) / ac;
	c = vec(vb, va) / ab + vec(vc, va) / ac;

	out.precision(12);
	out << fixed;
	out << a << ' ' << b << ' ' << c;

	return 0;
}