#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")

#include <iostream>
#include <stdio.h>
//#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using ll = long long;
using ull = unsigned long long;
using ld = long double;
//�KAN
//template<typename T>
//using pair2<T> = pair<T, T>;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
#define all(a) a.begin(), a.end()

template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

using namespace std;

static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const double PI = 3.1415926535897932384626433832795;

struct line {
	ll a, b, c;

	line(ll a_, ll b_, ll c_) {
		a = a_;
		b = b_;
		c = c_;
	}
};

struct Vector {
	ll x, y;

	Vector(ll x_arg = 0, ll y_arg = 0) {
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

ll scal(Vector v1, Vector v2) {
	return v1.x * v2.x + v1.y * v2.y;
}

ll vec(Vector v1, Vector v2) {
	return v1.x * v2.y - v2.x * v1.y;
}

int main() {
	freopen("goat5.in", "r", stdin);
	freopen("goat5.out", "w", stdout);

	Vector a, o, b, p;
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &a.x, &a.y, &o.x, &o.y, &b.x, &b.y, &p.x, &p.y);
	
	if (vec(a - o, p - o) >= 0 && vec(a - o, b - o) >= 0 && vec(p - o, b - o) >= 0 ||
		vec(a - o, p - o) <= 0 && vec(a - o, b - o) <= 0 && vec(p - o, b - o) <= 0)
		printf("YES");
	else
		printf("NO");

	//printf("\n\n%d\n%d\n%d\n%d\n%d\n%d", scal(b - o, p - o), scal(o - b, p - b), scal(a - o, p - o), scal(o - a, p - a), vec(a - p, o - p), vec(b - p, o - p));

	return 0;
}