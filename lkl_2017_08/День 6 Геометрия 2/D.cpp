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

bool operator ==(const Vector &a, const Vector &b) {
	return a.x == b.x && a.y == b.y;
}

bool operator <(const Vector &a, const Vector &b) {
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
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

ll length2(Vector a) {
	return a.x * a.x + a.y * a.y;
}

bool comp(Vector a, Vector b) {
	return a.y < b.y;
}

vector<Vector> polygon;

bool point_in_angle(Vector a, Vector o, Vector b, Vector p) {
	if (vec(a - o, p - o) >= 0 && vec(a - o, b - o) >= 0 && vec(p - o, b - o) >= 0 ||
		vec(a - o, p - o) <= 0 && vec(a - o, b - o) <= 0 && vec(p - o, b - o) <= 0)
		return true;
	return false;
}

int binsearch_polygon(Vector a) {
	int left = 1, right = polygon.size() - 1;
	while (right - left > 1) {
		int middle = (left + right) / 2;
		if (point_in_angle(polygon[middle], polygon[0], polygon[right], a))
			left = middle;
		else
			right = middle;
	}

	return left;
}

int main() {
	freopen("theodore.in", "r", stdin);
	freopen("theodore.out", "w", stdout);

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	polygon.resize(n);
	forn(i, 0, n)
		scanf("%lld%lld", &polygon[i].x, &polygon[i].y);


	int sum = 0;
	forn(i, 0, m) {
		Vector point;
		scanf("%lld%lld", &point.x, &point.y);

		int left_point = binsearch_polygon(point);
		if (point_in_angle(polygon[left_point], polygon[0], polygon[left_point + 1], point) &&
			point_in_angle(polygon[0], polygon[left_point], polygon[left_point + 1], point))
			sum++;
	}

	//printf("%d\n", sum);

	if (sum < k)
		printf("NO");
	else
		printf("YES");

	return 0;
}