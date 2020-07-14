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

double dist(pair<double, double> a, pair<double, double> b) {
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Vector O;
	scanf("%lld%lld", &O.x, &O.y);

	int r;
	scanf("%d", &r);

	line l = line(0, 0, 0);
	scanf("%lld%lld%lld", &l.a, &l.b, &l.c);

	//printf("Input:\nO = { %lld, %lld }, R = %d\nl: %lldx + %lldy + %lld = 0", O.x, O.y, r, l.a, l.b, l.c);

	double h = abs(l.a * O.x + l.b * O.y + l.c) / sqrt(l.a * l.a + l.b * l.b);
	//printf("\n---------------------------------\nProgram:\nh = %.9f\n", h);

	if (h > r + EPS) {
		printf("0");
		return 0;
	}

	Vector n = Vector(l.a, l.b);
	pair<double, double> new_n;
	new_n.first = n.x * h / sqrt(length2(n));
	new_n.second = n.y * h / sqrt(length2(n));

	//printf("Vector normal = (%lld, %lld)\nupdated normal = (%.9f, %.9f)\n", n.x, n.y, new_n.first, new_n.second);

	pair<double, double> A;
	if (l.a * (O.x + new_n.first) + l.b * (O.y + new_n.second) + l.c < EPS)
		A = { O.x + new_n.first, O.y + new_n.second };
	else
		A = { O.x - new_n.first, O.y - new_n.second };

	if (abs(h - r) < EPS) {
		printf("1\n%.9f %.9f", A.first, A.second);
		return 0;
	}

	//printf("A = (%.9f %.9f)", A.first, A.second);

	double d = sqrt(r * r - h * h);
	//printf("\nd = %.9f", d);

	pair<double, double> point_l = { A.first + l.b, (l.b == 0 ? A.second + l.a : -(l.a * (A.first + l.b) + l.c) / l.b) };
	//printf("\nrandom point on l = (%.9f, %.9f)\ndistance from point to A = %.9f\n---------------------------------\nAnswer:\n", point_l.first, point_l.second, sqrt((A.first - point_l.first) * (A.first - point_l.first) + (A.second - point_l.second) * (A.second - point_l.second)));

	pair<double, double> B1 = { A.first + ((A.first - point_l.first) / dist(A, point_l)) * d,
		A.second + ((A.second - point_l.second) / dist(A, point_l)) * d };
	pair<double, double> B2 = { A.first - ((A.first - point_l.first) / dist(A, point_l)) * d,
		A.second - ((A.second - point_l.second) / dist(A, point_l)) * d };

	if (abs(B1.first - B2.first) < EPS) {
		if (B1.second > B2.second + EPS)
			swap(B1, B2);
	}
	else {
		if (B1.first > B2.first + EPS)
			swap(B1, B2);
	}

	printf("2\n%.9f %.9f\n%.9f %.9f", B1.first, B1.second, B2.first, B2.second);

	return 0;
}