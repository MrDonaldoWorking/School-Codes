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

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	forn(i, 1, n + 1) {
		forn(j, 1, m + 1)
			scanf("%d", &dp[i][j]);
	}

	int maxlength = 0;
	forn(i, 1, n + 1) {
		forn(j, 1, m + 1)
			if (dp[i][j] != 0) {
				dp[i][j] = min(min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]) + 1;
				amax(maxlength, dp[i][j]);
			}
	}

	printf("%d", maxlength);

	return 0;
}