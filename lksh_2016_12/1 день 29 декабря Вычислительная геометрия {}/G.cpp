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

ifstream in("point3.in");
ofstream out("point3.out");

struct Vector {
	int x, y;

	Vector(int x_arg = 0, int y_arg = 0) {
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

Vector operator *(const Vector &u, int k) {
	return Vector(k * u.x, k * u.y);
}

Vector operator *(int k, const Vector &u) {
	return Vector(k * u.x, k * u.y);
}

int scal(Vector v1, Vector v2) {
	return v1.x * v2.x + v1.y * v2.y;
}

int vec(Vector v1, Vector v2) {
	return v1.x * v2.y - v2.x * v1.y;
}

int main() {
	Vector v0, v1, v2;
	in >> v0.x >> v0.y >> v1.x >> v1.y >> v2.x >> v2.y;

	Vector a = v0 - v1, b = v2 - v1, c = v0 - v2, d = v1 - v2;
	if (vec(a, b) == 0) {
		if (scal(a, b) >= 0) {
			if (scal(c, d) >= 0)
				out << "YES";
			else
				out << "NO";
		}
		else
			out << "NO";
	}
	else
		out << "NO";

	return 0;
}