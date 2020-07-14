#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")

#include <iostream>
#include <stdio.h>
//#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

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

int main() {
	freopen("knight.in", "r", stdin);
	freopen("knight.out", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);

	vector<vector<ll>> a(n + 4, vector<ll>(m + 4, 0));
	a[2][2] = 1;
	forn(x, 3, n + 2) {
		int save = x;
		int y = 2;
		while (x > 1 && y < m + 2) {
			a[x][y] = a[x - 1][y - 2] + a[x - 2][y - 1] + a[x + 1][y - 2] + a[x - 2][y + 1];
			x--;
			y++;
		}
		x = save;
	}

	forn(y, 3, m + 2) {
		int save = y;
		int x = n + 1;
		while (x > 1 && y < m + 2) {
			a[x][y] = a[x - 1][y - 2] + a[x - 2][y - 1] + a[x + 1][y - 2] + a[x - 2][y + 1];
			x--;
			y++;
		}
		y = save;
	}

	printf("%lld", a[n + 1][m + 1]);

	return 0;
}