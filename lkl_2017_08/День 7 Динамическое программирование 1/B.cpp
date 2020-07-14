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
	freopen("lcs.in", "r", stdin);
	freopen("lcs.out", "w", stdout);

	int n;
	scanf("%d", &n);

	vector<int> a(n);
	forn(i, 0, n)
		scanf("%d", &a[i]);

	int m;
	scanf("%d", &m);

	vector<int> b(m);
	forn(i, 0, m)
		scanf("%d", &b[i]);

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	forn(i, 1, n + 1) {
		forn(j, 1, m + 1) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (a[i - 1] == b[j - 1])
				amax(dp[i][j], dp[i - 1][j - 1] + 1);
		}
	}

	/*forn(i, 0, n + 1) {
		forn(j, 0, m + 1)
			printf("%d ", dp[i][j]);
		printf("\n");
	}*/

	vector<int> ans;
	while (n > 0 && m > 0) {
		if (a[n - 1] == b[m - 1]) {
			ans.push_back(a[n - 1]);
			n--;
			m--;
			continue;
		}

		if (dp[n - 1][m] > dp[n][m - 1])
			n--;
		else
			m--;
	}

	int q = ans.size();
	printf("%d\n", q);
	form(i, q, 0)
		printf("%d ", ans[i]);

	return 0;
}