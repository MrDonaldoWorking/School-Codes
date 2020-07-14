#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

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
const double EPS = 1e-7;

struct line {
	double a, b, c;

	line(double a_, double b_, double c_) {
		a = a_;
		b = b_;
		c = c_;
	}
};

struct Vector {
	double x, y;

	Vector(double x_arg = 0, double y_arg = 0) {
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

Vector operator *(const Vector &u, double k) {
	return Vector(k * u.x, k * u.y);
}

Vector operator *(double k, const Vector &u) {
	return Vector(k * u.x, k * u.y);
}

Vector operator /(const Vector &u, double k) {
	return Vector(u.x / k, u.y / k);
}

Vector operator /(double k, const Vector &u) {
	return Vector(k / u.x, k / u.y);
}

bool operator <(const Vector &a, const Vector &b) {
	if (abs(a.x - b.x) < EPS)
		return a.y + EPS < b.y;
	return a.x + EPS < b.x;
}

double scal(Vector &v1, Vector &v2) {
	return v1.x * v2.x + v1.y * v2.y;
}

double vec(Vector &v1, Vector &v2) {
	return v1.x * v2.y - v2.x * v1.y;
}

line LineFromTwoPoints(Vector a, Vector b) {
	return{ a.y - b.y, b.x - a.x, vec(a, b) };
}

//cos a = 0!
line LineFromLineAndPoint(line a, Vector b) {
	return{ -a.b, a.a, a.b * b.x - a.a * b.y };
}

Vector NormalVector(line a) {
	return{ a.a, a.b };
}

Vector lineintersections(line ab, line cd) {
	return{ (ab.b * cd.c - ab.c * cd.b) / (ab.a * cd.b - ab.b * cd.a),
		(ab.c * cd.a - ab.a * cd.c) / (ab.a * cd.b - ab.b * cd.a) };
}

double dist(Vector a) {
	return sqrt(a.x * a.x + a.y * a.y);
}

double dist2(Vector a, Vector b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double XOnLine(line a, double y) {
	return -(a.b * y + a.c) / a.a;
}

bool operator <(const line &a, const line &b) {
	return XOnLine(a, 0) + EPS < XOnLine(b, 0);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	double r, q;
	//scanf("%d%d%d", &r, &n, &q);
	cin >> r >> n >> q;

	r /= 1000;
	q /= 1000;

	Vector O, v;
	//scanf("%d%d%d%d", &O.x, &O.y, &v.x, &v.y);
	cin >> O.x >> O.y >> v.x >> v.y;

	line l = LineFromTwoPoints(O, O + v);
	Vector n1 = NormalVector(l);
	Vector n2 = -NormalVector(l);

	Vector normaln1 = n1 * (q + r) / dist(n1);
	Vector normaln2 = n2 * (q + r) / dist(n2);

	Vector PointOfTouch1 = normaln1 + O;
	Vector PointOfTouch2 = normaln2 + O;

	//printf("%.9f %.9f\n%.9f %.9f\n", PointOfTouch1.x, PointOfTouch1.y, PointOfTouch2.x, PointOfTouch2.y);

	line TouchableLine1 = LineFromTwoPoints(PointOfTouch1, PointOfTouch1 + v);
	line TouchableLine2 = LineFromTwoPoints(PointOfTouch2, PointOfTouch2 + v);
	if (TouchableLine2 < TouchableLine1)
		swap(TouchableLine1, TouchableLine2);

	//printf("%.9f %.9f %.9f\n%.9f %.9f %.9f\n", TouchableLine1.a, TouchableLine1.b, TouchableLine1.c,
		//TouchableLine2.a, TouchableLine2.b, TouchableLine2.c);

	ll ans = 0;
	forn(i, 0, n) {
		Vector MostLeft = Vector(-(i), i);
		Vector MostRight = Vector(i, i);

		int QuantityOfPointsLeftSide;
		if (abs(XOnLine(TouchableLine1, i) - floor(XOnLine(TouchableLine1, i))) < EPS) { //XOnLine != double
			int x = (int)floor(XOnLine(TouchableLine1, i));
			if (x < -i)
				QuantityOfPointsLeftSide = 0;
			else {
				if (abs(x) % 2 == i % 2) //Point on Line
					QuantityOfPointsLeftSide = (x - (-i)) / 2;
				else
					QuantityOfPointsLeftSide = (x - (-i)) / 2 + 1;
				amin(QuantityOfPointsLeftSide, i + 1);
			}
		}
		else {
			if (MostLeft.x > EPS + XOnLine(TouchableLine1, i))
				QuantityOfPointsLeftSide = 0;
			else
				QuantityOfPointsLeftSide = min(i + 1, (int)floor((XOnLine(TouchableLine1, i) - MostLeft.x) / 2.0) + 1);
		}

		int QuantityOfPointsRightSide;
		if (abs(XOnLine(TouchableLine2, i) - floor(XOnLine(TouchableLine2, i))) < EPS) { //XOnLine != double
			int x = (int)floor(XOnLine(TouchableLine2, i));
			if (x > i)
				QuantityOfPointsRightSide = 0;
			else {
				if (abs(x) % 2 == i % 2) //Point on Line
					QuantityOfPointsRightSide = (i - x) / 2;
				else
					QuantityOfPointsRightSide = (i - x) / 2 + 1;
				amin(QuantityOfPointsRightSide, i + 1);
			}
		}
		else {
			if (MostRight.x + EPS < XOnLine(TouchableLine2, i))
				QuantityOfPointsRightSide = 0;
			else
				QuantityOfPointsRightSide = min(i + 1, (int)floor((MostRight.x - XOnLine(TouchableLine2, i)) / 2.0) + 1);
		}

		ans += (i + 1) - QuantityOfPointsLeftSide - QuantityOfPointsRightSide;
	}

	printf("%lld", ans);

	return 0;
}