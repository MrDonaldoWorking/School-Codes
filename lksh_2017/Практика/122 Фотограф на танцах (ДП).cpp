#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")

#include <iostream>
#include <stdio.h>
//#include <fstream>
#include <vector>
#include <algorithm>

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
	freopen("photographer.in", "r", stdin);
	freopen("photographer.out", "w", stdout);

	int n, t, k;
	scanf("%d%d%d", &n, &t, &k);

	struct posit {
		int pos;
		int val;
	};
	vector<vector<posit>> a(t, vector<posit>(4));
	forn(i, 0, t)
		forn(j, 0, 4)
		scanf("%d%d", &a[i][j].pos, &a[i][j].val);

	/*forn(i, 0, t)
	forn(j, 0, 4)
	printf("%d %d\n", a[i][j].pos, a[i][j].val);*/

	vector<vector<int>> dp(n, vector<int>(t, 0));
	forn(i, 0, n) {
		forn(j, 0, 4)
			if (a[0][j].pos - 1 >= i)
				dp[i][0] += a[0][j].val / (1 + a[0][j].pos - 1 - i);
	}

	forn(q, 1, t) {
		forn(i, 0, n) {
			forn(j, 0, 4)
				if (a[q][j].pos - 1 >= i)
					dp[i][q] += a[q][j].val / (1 + a[q][j].pos - 1 - i);

			int add = 0;
			forn(j, max(0, i - k), min(n, i + k + 1))
				amax(add, dp[j][q - 1]);

			dp[i][q] += add;
		}
	}

	int ans = 0;
	forn(i, 0, n)
		amax(ans, dp[i][t - 1]);

	printf("%d", ans);

	return 0;
}