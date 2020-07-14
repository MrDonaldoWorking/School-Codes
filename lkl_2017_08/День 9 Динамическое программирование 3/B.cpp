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

int popcount(int mask) {
	int k = 0;
	int ans = 0;
	while (mask >= (1 << k)) {
		if ((mask >> k) & 1 == 1)
			ans++;
		k++;
	}

	return ans;
}

int main() {
	freopen("network.in", "r", stdin);
	freopen("network.out", "w", stdout);

	int n;
	scanf("%d", &n);

	char c;
	vector<vector<int>> graph(n);
	forn(i, 0, n) {
		scanf("%c", &c);
		forn(j, 0, n) {
			scanf("%c", &c);
			if (c == 'Y')
				graph[i].push_back(j);
		}
	}

	vector<bool> dp((1 << n), false);
	dp[0] = true;
	forn(mask, 0, (1 << n)) {
		if (dp[mask]) {
			forn(v, 0, n) {
				if (!(mask & (1 << v))) {
					for (int u : graph[v]) {
						if (!(mask & (1 << u))) {
							dp[mask | (1 << v) | (1 << u)] = true;
						}
					}
				}
			}
		}
	}

	int ans = 0;
	forn(mask, 0, (1 << n)) {
		if (dp[mask])
			amax(ans, popcount(mask));
		//printf("%d == %d\n", mask, popcount(mask));
	}

	printf("%d", ans);

	return 0;
}