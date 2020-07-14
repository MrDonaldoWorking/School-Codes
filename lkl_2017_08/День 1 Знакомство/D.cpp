#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")

#include <iostream>
#include <stdio.h>
//#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>

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

int scal(int x1, int y1, int x2, int y2) {
	return x1 * x2 + y1 * y2;
}

int vec(int x1, int y1, int x2, int y2) {
	return x1 * y2 - x2 * y1;
}

int main() {
	freopen("distance1.in", "r", stdin);
	freopen("distance1.out", "w", stdout);

	int xc, yc, xa, ya, xb, yb;
	scanf("%d%d%d%d%d%d", &xc, &yc, &xa, &ya, &xb, &yb);

	int A = ya - yb, B = xb - xa, C = vec(xa, ya, xb, yb);

	double minans = abs(A * xc + B * yc + C) / sqrt(A * A + B * B);
	double ans = min(sqrt((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc)), sqrt((xb - xc) * (xb - xc) + (yb - yc) * (yb - yc)));

	printf("%.9f\n", minans);
	if (scal(xb - xa, yb - ya, xc - xa, yc - ya) > 0)
		printf("%.9f\n", minans);
	else
		printf("%.9f\n", ans);

	if (scal(xb - xa, yb - ya, xc - xa, yc - ya) > 0 && scal(xa - xb, ya - yb, xc - xb, yc - yb) > 0)
		printf("%.9f\n", minans);
	else
		printf("%.9f\n", ans);

	return 0;
}