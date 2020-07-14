#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")

#include <iostream>
#include <stdio.h>
#include <fstream>
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
	freopen("avia.in", "r", stdin);
	freopen("avia.out", "w", stdout);

	int n, m, k, s, f;
	scanf("%d%d%d%d%d", &n, &m, &k, &s, &f);

	vector<int> from(m);
	vector<int> to(m);
	vector<int> w(m);
	forn(i, 0, m)
		scanf("%d%d%d", &from[i], &to[i], &w[i]);

	vector<vector<int>> length(n, vector<int>(n, INF));
	length[s - 1][0] = 0;
	forn(kk, 0, n - 1) {
		forn(i, 0, m)
			amin(length[to[i] - 1][kk + 1], length[from[i] - 1][kk] + w[i]);
	}

	int min_ = INF;
	forn(i, 1, min(n, k + 1)) {
		amin(min_, length[f - 1][i]);
	}

	printf("%d", (min_ == INF ? -1 : min_));

	return 0;
}