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
	int a, b, c;

	line(int a_, int b_, int c_) {
		a = a_;
		b = b_;
		c = c_;
	}
};

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
	freopen("perim.in", "r", stdin);
	freopen("perim.out", "w", stdout);

	int n, r;
	scanf("%d%d", &n, &r);

	vector<Vector> a(n);
	forn(i, 0, n)
		scanf("%d%d", &a[i].x, &a[i].y);
	a.push_back(a[0]);

	double sum = 0;
	forn(i, 0, n) {
		sum += sqrt((a[i + 1].x - a[i].x) * (a[i + 1].x - a[i].x) + (a[i + 1].y - a[i].y) * (a[i + 1].y - a[i].y));
	}

	printf("%.9f", PI * r * 2 + sum);
	
	return 0;
}