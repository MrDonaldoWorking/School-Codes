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
//©KAN
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

ld dist(Vector a, Vector c) {
	return (ld)sqrt((a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y));
}

int main() {
	freopen("goat3.in", "r", stdin);
	freopen("goat3.out", "w", stdout);

	Vector a, b, c;
	scanf("%lld%lld%lld%lld%lld%lld", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);

	ll l;
	scanf("%lld", &l);

	if (a.x == b.x && a.y == b.y) {
		printf("%.9llf\n%.9llf", max(dist(a, c) - l, (ld)0.0), max(dist(a, c) - l, (ld)0.0));
		return 0;
	}

	ll A = a.y - b.y, B = b.x - a.x, C = vec(a, b);

	ld minans;
	if (scal(b - a, c - a) * scal(a - b, c - b) >= 0)
		minans = abs(A * c.x + B * c.y + C) / sqrt(A * A + B * B);
	else
		minans = min(dist(a, c), dist(b, c));
	ld ans = max(dist(a, c), dist(b, c));

	//printf("%.9f %.9f %lld\n", minans, ans, l);

	printf("%.9llf\n", max(minans - l, (ld)0.0));
	printf("%.9llf\n", max(ans - l, (ld)0.0));

	return 0;
}