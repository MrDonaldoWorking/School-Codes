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
vector<int> node;
vector<int> dp0;
vector<int> dp1;

void dfs(int v) {
	if (graph[v].empty()) {
		dp0[v] = 0;
		dp1[v] = node[v];
		return;
	}

	int s = 0;
	for (int u : graph[v]) {
		dfs(u);
		dp0[v] += max(dp1[u], dp0[u]);
		s += dp0[u];
	}
	amax(dp1[v], node[v] + s);
}

int main() {
	freopen("selectw.in", "r", stdin);
	freopen("selectw.out", "w", stdout);

	int n;
	scanf("%d", &n);

	int root;
	graph.resize(n);
	node.resize(n);
	forn(i, 0, n) {
		int x, y;
		scanf("%d%d", &x, &y);

		if (x == 0) {
			root = i;
			node[i] = y;
			continue;
		}

		graph[x - 1].push_back(i);
		node[i] = y;
	}

	dp0.resize(n);
	dp1.resize(n);

	dfs(root);

	printf("%d", max(dp0[root], dp1[root]));
	
	return 0;
}