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

vector<Vector> a;

ll mindist(int l, int r) {
	if (l == r)
		return INFL;
	if (l + 1 == r) {
		if (a[l].y > a[r].y)
			swap(a[l], a[r]);
		return length2(a[l] - a[r]);
	}

	int m = (l + r) / 2;
	ll h1 = mindist(l, m);
	ll h2 = mindist(m + 1, r);
	ll h = min(h1, h2);
	inplace_merge(a.begin() + l, a.begin() + m + 1, a.begin() + r + 1, comp);

	forn(i, l, r + 1) {
		forn(j, i + 1, r + 1) {
			if (a[j].y - a[i].y >= h)
				break;
			h = min(h, length2(a[i] - a[j]));
		}
	}

	return h;
}

int main() {
	freopen("nearest.in", "r", stdin);
	freopen("nearest.out", "w", stdout);

	int n;
	scanf("%d", &n);

	a.resize(n);
	forn(i, 0, n)
		scanf("%lld%lld", &a[i].x, &a[i].y);

	sort(all(a));
	//a.resize(unique(all(a)) - a.begin());

	printf("%.9f", sqrt(mindist(0, n - 1)));

	return 0;
}