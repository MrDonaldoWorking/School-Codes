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

//static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 2000000000;
const int mod = 1e9 + 7;

int main() {
	freopen("salesman.in", "r", stdin);
	freopen("salesman.out", "w", stdout);

	int n;
	scanf("%d", &n);

	vector<vector<int>> graph(n, vector<int>(n));
	forn(i, 0, n) {
		forn(j, 0, n)
			if (i != j)
				graph[i].push_back(j);
	}

	vector<vector<int>> cost(n, vector<int>(n));
	forn(i, 0, n) {
		forn(j, 0, n) {
			scanf("%d", &cost[i][j]);
		}
	}

	vector<vector<int>> dp((1 << n), vector<int>(n, INF));
	forn(i, 0, n) {
		dp[(1 << i)][i] = 0;
	}
	vector<vector<int>> prev((1 << n), vector<int>(n, 0));
	forn(mask, 0, (1 << n)) {
		forn(last, 0, n) {
			if ((mask >> last) & 1 == 1) {
				for (int u : graph[last]) {
					if (!(mask & (1 << u))) {
						//amin(dp[(mask) | (1 << u)][u], dp[mask][last] + cost[last][u]);
						if (dp[(mask) | (1 << u)][u] > dp[mask][last] + cost[last][u]) {
							dp[(mask) | (1 << u)][u] = dp[mask][last] + cost[last][u];
							prev[(mask) | (1 << u)][u] = last;
						}
					}
				}
			}
		}
	}

	int ans = INF;
	int lastv = 0;
	for (int i = 0; i < n; i++ /*dp[(1 << n) - 1]*/) {
		if (ans > dp[(1 << n) - 1][i]) {
			ans = dp[(1 << n) - 1][i];
			lastv = i;
		}
	}

	printf("%d\n", ans);

	vector<int> ansv;
	ansv.push_back(lastv);
	int mask = (1 << n) - 1;
	forn(i, 0, n) {
		int newmask = mask ^ (1 << lastv);
		int newv = prev[mask][lastv];
		mask = newmask;
		lastv = newv;
		ansv.push_back(lastv);
	}

	form(i, n, 0) {
		printf("%d ", ansv[i] + 1);
	}
	
	return 0;
}