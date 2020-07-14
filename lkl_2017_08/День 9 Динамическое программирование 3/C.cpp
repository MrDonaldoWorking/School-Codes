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
const int mod = 1e9 + 7;

int n;

bool ok(int p, int p1) {
	forn(i, 0, n - 1)
		if (((p >> i) & 1) == ((p1 >> i) & 1) && ((p >> (i + 1)) & 1) == ((p1 >> (i + 1)) & 1) && ((p >> i) & 1) == ((p >> (i + 1)) & 1))
			return false;

	return true;
}

int main() {
	freopen("nice1.in", "r", stdin);
	freopen("nice1.out", "w", stdout);

	int m;
	scanf("%d%d", &n, &m);
	if (n > m)
		swap(n, m);

	int p = (1 << n);
	vector<vector<int>> ans(m, vector<int>(p, 0));
	forn(i, 0, p)
		ans[0][i] = 1;

	forn(i, 1, m) {
		forn(a, 0, p) {
			forn(b, 0, p) {
				if (ok(a, b))
					ans[i][a] += ans[i - 1][b];
			}
		}
	}

	int sum = 0;
	forn(i, 0, p) {
		sum += ans[m - 1][i];
	}

	printf("%d", sum);
	
	return 0;
}