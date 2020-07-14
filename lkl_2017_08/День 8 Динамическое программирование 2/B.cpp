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
const double EPS = 1e-5;

vector<vector<int>> graph;
vector<ll> dp0;
vector<ll> dp1;
vector<ll> dp2;
vector<bool> used;
vector<bool> counted;

void dfs(int v) {
	if (used[v])
		return;

	used[v] = true;

	if (v != 0 && graph[v].size() == 1) {//it is leaf
		dp0[v] = 1;
		dp1[v] = INF;
		dp2[v] = 0;
		counted[v] = true;
		return;
	}

	int s = 0;
	for (int u : graph[v]) {
		dfs(u);
		if (counted[u])
			s += min(dp1[u], dp0[u]);
	}
	for (int u : graph[v]) {
		if (counted[u]) {
			dp0[v] += min(dp0[u], min(dp1[u], dp2[u]));
			amin(dp1[v], s - min(dp1[u], dp0[u]) + dp0[u]);
			dp2[v] += dp1[u];
		}
	}
	dp0[v] += 1;
	counted[v] = true;
}

int main() {
	freopen("pasture.in", "r", stdin);
	freopen("pasture.out", "w", stdout);

	int n;
	scanf("%d", &n);

	graph.resize(n);
	forn(i, 0, n - 1) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dp0.resize(n, 0);
	dp1.resize(n, INF);
	dp2.resize(n, 0);
	used.resize(n, false);
	counted.resize(n, false);

	dfs(0);//0 == root

		   /*forn(i, 0, n) {
		   printf("%lld %lld %lld\n", dp0[i], dp1[i], dp2[i]);
		   }*/

	printf("%lld", min(dp0[0], dp1[0]));

	return 0;
}