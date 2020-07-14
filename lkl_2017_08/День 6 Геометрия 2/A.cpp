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
const double EPS = 1e-5;

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

pair<double, double> lineintersections(line ab, line cd) {
	return{ (double)(ab.b * cd.c - ab.c * cd.b) / (ab.a * cd.b - ab.b * cd.a), (double)(ab.c * cd.a - ab.a * cd.c) / (ab.a * cd.b - ab.b * cd.a) };
}

bool point_on_segment(Vector v0, Vector v1, Vector v2) {
	Vector a = v0 - v1, b = v2 - v1, c = v0 - v2, d = v1 - v2;
	if (vec(a, b) == 0) {
		if (scal(a, b) >= 0) {
			if (scal(c, d) >= 0)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

int main() {
	freopen("point.in", "r", stdin);
	freopen("point.out", "w", stdout);

	int n;
	scanf("%d", &n);

	Vector find;
	scanf("%lld%lld", &find.x, &find.y);

	vector<Vector> a(n);
	forn(i, 0, n)
		scanf("%lld%lld", &a[i].x, &a[i].y);
	a.push_back(a[0]);

	forn(i, 0, n) {
		if (point_on_segment(find, a[i], a[i + 1])) {
			printf("YES");
			return 0;
		}
	}

	line ray = line(0, 1, -find.y);
	int sum = 0;
	forn(i, 0, n) {
		if (a[i].y == a[i + 1].y)
			continue;

		if (a[i].y == find.y && a[i].x > find.x) {
			if (a[i + 1].y < a[i].y)
				sum++;
			continue;
		}
		if (a[i + 1].y == find.y && a[i + 1].x > find.x) {
			if (a[i].y < a[i + 1].y)
				sum++;
			continue;
		}

		if (a[i].y > a[i + 1].y && a[i + 1].y > find.y)
			continue;
		if (a[i + 1].y > a[i].y && a[i].y > find.y)
			continue;
		if (a[i].y < a[i + 1].y && a[i + 1].y < find.y)
			continue;
		if (a[i + 1].y < a[i].y && a[i].y < find.y)
			continue;

		if (a[i].y > a[i + 1].y) {
			if (vec(find - a[i + 1], a[i] - a[i + 1]) < 0)
				sum++;
			continue;
		}
		if (a[i + 1].y > a[i].y) {
			if (vec(find - a[i], a[i + 1] - a[i]) < 0)
				sum++;
			continue;
		}
	}

	if (sum % 2 == 0)
		printf("NO");
	else
		printf("YES");

	return 0;
}