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

int main() {
	freopen("azeroth.in", "r", stdin);
	freopen("azeroth.out", "w", stdout);

	int n;
	scanf("%d", &n);

	if (n == 1) {
		printf("%.9f", 0.0);
		return 0;
	}

	vector<Vector> a(n);
	Vector mostleft = Vector(INF, INF);
	forn(i, 0, n) {
		scanf("%lld%lld", &a[i].x, &a[i].y);
		if (a[i] < mostleft)
			mostleft = a[i];
	}

	sort(all(a), [mostleft](Vector &a, Vector &b) {
		return vec(a - mostleft, b - mostleft) > 0 ||
			vec(a - mostleft, b - mostleft) == 0 && length2(a - mostleft) < length2(b - mostleft);
	});

	a.resize(unique(all(a)) - a.begin());
	n = a.size();

	vector<Vector> curr_pt;
	curr_pt.push_back(a[0]);
	curr_pt.push_back(a[1]);
	forn(i, 2, n) {
		while (curr_pt.size() >= 2 && vec(curr_pt.back() - curr_pt[curr_pt.size() - 2], a[i] - curr_pt.back()) <= 0)
			curr_pt.pop_back();
		curr_pt.push_back(a[i]);
	}
	curr_pt.push_back(curr_pt[0]);

	double sumlength = 0;
	int sz = curr_pt.size() - 1;
	forn(i, 0, sz)
		sumlength += sqrt(length2(curr_pt[i + 1] - curr_pt[i]));

	printf("%.9f", sumlength);

	return 0;
}