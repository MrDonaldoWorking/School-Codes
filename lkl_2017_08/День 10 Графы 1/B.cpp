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

struct node {
	int to;
	int num;
};

vector<vector<node>> graph;
vector<bool> used;
int timer;
vector<int> tin, fup;
set<int> ans;

void dfs(int v, int p = -1) {
	used[v] = true;
	tin[v] = fup[v] = timer++;

	for (auto to : graph[v]) {
		if (to.to == p)
			continue;

		if (used[to.to])
			fup[v] = min(fup[v], tin[to.to]);

		else {
			dfs(to.to, v);
			fup[v] = min(fup[v], fup[to.to]);
			if (fup[to.to] > tin[v])
				ans.insert(to.num);
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);

	graph.resize(n);
	forn(i, 0, m) {
		int from, to;
		scanf("%d%d", &from, &to);

		graph[from - 1].push_back({ to - 1, i });
		graph[to - 1].push_back({ from - 1, i });
	}

	used.resize(n, false);
	tin.resize(n);
	fup.resize(n);
	timer = 0;
	dfs(0);

	printf("%d\n", ans.size());
	for (auto i : ans)
		printf("%d ", i + 1);

	return 0;
}