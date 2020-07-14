#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")

#include <iostream>
//#include <stdio.h>
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
const double PI = 3.1415926535897932384626433832795;

vector<bool> used;
vector<vector<int>> graph;

void dfs(int v, vector<int> &dp) {
	if (used[v])
		return;

	used[v] = true;

	for (int u : graph[v]) {
		dfs(u, dp);
		amax(dp[v], dp[u] + 1);
	}
}

int main() {
	freopen("longpath.in", "r", stdin);
	freopen("longpath.out", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);

	vector<int> dp(n, 0);
	graph.resize(n);
	forn(i, 0, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;

		graph[x].push_back(y);
	}

	used.resize(n);
	forn(i, 0, n)
		dfs(i, dp);

	int ans = -1;
	forn(i, 0, n)
		amax(ans, dp[i]);

	printf("%d", ans);

	return 0;
}