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

inline ll area(Vector a, Vector b, Vector c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline bool intersect_1(ll a, ll b, ll c, ll d) {
	if (a > b)  swap(a, b);
	if (c > d)  swap(c, d);
	return max(a, c) <= min(b, d);
}

bool intersect(Vector a, Vector b, Vector c, Vector d) {
	bool ans;
	ans = intersect_1(a.x, b.x, c.x, d.x);
	ans = ans && intersect_1(a.y, b.y, c.y, d.y);
	ans = ans && area(a, b, c) * area(a, b, d) <= 0;
	ans = ans && area(c, d, a) * area(c, d, b) <= 0;
	return ans;
}

pair<double, double> lineintersections(line ab, line cd) {
	return{ (double)(ab.b * cd.c - ab.c * cd.b) / (ab.a * cd.b - ab.b * cd.a), (double)(ab.c * cd.a - ab.a * cd.c) / (ab.a * cd.b - ab.b * cd.a) };
}

int main() {
	freopen("goat6.in", "r", stdin);
	freopen("goat6.out", "w", stdout);

	Vector a, b, c, d;
	//while (cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y)
	//	/*scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y) == 8*/ {
		//printf("\n\n");
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y);

	bool ans = intersect(a, b, c, d);
	if (!ans) {
		printf("Empty");
		return 0;
	}

	if (a.x == b.x && a.y > b.y || a.x > b.x)
		swap(a, b);
	if (c.x == d.x && c.y > d.y || c.x > d.x)
		swap(c, d);

	line ab = line(a.y - b.y, b.x - a.x, vec(a, b));
	line cd = line(c.y - d.y, d.x - c.x, vec(c, d));

	if (a.x == b.x && b.x == c.x && c.x == d.x) {
		if (ab.a * cd.b == ab.b * cd.a) {
			if (b.x == c.x && b.y == c.y) {
				printf("%.9f\n%.9f", (double)b.x, (double)b.y);
				return 0;
				//continue;
			}
			if (a.x == d.x && a.y == d.y) {
				printf("%.9f\n%.9f", (double)a.x, (double)a.y);
				return 0;
				//continue;
			}
			if (a.y > c.y && b.y < d.y) {
				printf("%.9f\n%.9f\n%.9f\n%.9f", (double)a.x, (double)a.y, (double)b.x, (double)b.y);
				return 0;
				//continue;
			}
			if (a.y < c.y && b.y > d.y) {
				printf("%.9f\n%.9f\n%.9f\n%.9f", (double)c.x, (double)c.y, (double)d.x, (double)d.y);
				return 0;
				//continue;
			}
			if (a.y > c.y && b.y > d.y) {
				printf("%.9f\n%.9f\n%.9f\n%.9f", (double)a.x, (double)a.y, (double)d.x, (double)d.y);
				return 0;
				//continue;
			}
			printf("%.9f\n%.9f\n%.9f\n%.9f", (double)c.x, (double)c.y, (double)b.x, (double)b.y);
			return 0;
			//continue;
		}
	}
	else {
		if (ab.a * cd.b == ab.b * cd.a) {
			if (b.x == c.x && b.y == c.y) {
				printf("%.9f\n%.9f", (double)b.x, (double)b.y);
				return 0;
				//continue;
			}
			if (a.x == d.x && a.y == d.y) {
				printf("%.9f\n%.9f", (double)a.x, (double)a.y);
				return 0;
				//continue;
			}
			if (a.x > c.x && b.x < d.x) {
				printf("%.9f\n%.9f\n%.9f\n%.9f", (double)a.x, (double)a.y, (double)b.x, (double)b.y);
				return 0;
				//continue;
			}
			if (a.x < c.x && b.x > d.x) {
				printf("%.9f\n%.9f\n%.9f\n%.9f", (double)c.x, (double)c.y, (double)d.x, (double)d.y);
				return 0;
				//continue;
			}
			if (a.x > c.x && b.x > d.x) {
				printf("%.9f\n%.9f\n%.9f\n%.9f", (double)a.x, (double)a.y, (double)d.x, (double)d.y);
				return 0;
				//continue;
			}
			if (a.x == c.x && a.y == c.y) {
				if (b.x < d.x)
					printf("%.9f\n%.9f\n%.9f\n%.9f", (double)a.x, (double)a.y, (double)b.x, (double)b.y);
				else
					printf("%.9f\n%.9f\n%.9f\n%.9f", (double)a.x, (double)a.y, (double)d.x, (double)d.y);
				return 0;
				//continue;
			}
			if (b.x == d.x && b.y == d.y) {
				if (c.x > a.x)
					printf("%.9f\n%.9f\n%.9f\n%.9f", (double)c.x, (double)c.y, (double)d.x, (double)d.y);
				else
					printf("%.9f\n%.9f\n%.9f\n%.9f", (double)a.x, (double)a.y, (double)b.x, (double)b.y);
				return 0;
				//continue;
			}
			printf("%.9f\n%.9f\n%.9f\n%.9f", (double)c.x, (double)c.y, (double)b.x, (double)b.y);
			return 0;
			//continue;
		}
		else
			printf("%.9f\n%.9f", lineintersections(ab, cd).first, lineintersections(ab, cd).second);
	}

	return 0;
}