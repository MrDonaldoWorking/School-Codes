#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")

#include <iostream>
#include <stdio.h>
//#include <fstream>
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
const double PI = 3.1415926535897932384626433832795;
const double EPS = 1e-5;to

int n, m, cnt;
vector<vector<int>> graph;
vector<vector<int>> notgraph;
vector<bool> was;
vector<int> ts;
vector<int> comp;

void topsort(int v) {
	if (was[v])
		return;
	was[v] = true;

	for (int u : graph[v])
		topsort(u);

	ts.push_back(v);
}

void component(int v) {
	if (was[v])
		return;
	was[v] = true;
	comp[v] = cnt;

	for (int u : notgraph[v])
		component(u);
}

int main() {
	freopen("condense2.in", "r", stdin);
	freopen("condense2.out", "w", stdout);

	scanf("%d%d", &n, &m);

	graph.resize(n);
	notgraph.resize(n);
	forn(i, 0, m) {
		int from, to;
		scanf("%d%d", &from, &to);

		graph[from - 1].push_back(to - 1);
		notgraph[to - 1].push_back(from - 1);
	}

	/*forn(i, 0, n) {
		printf("%d: ", i);
		for (int j : graph[i])
			printf("%d ", j);
		printf("\n");
	}*/

	was.resize(n, false);
	forn(i, 0, n)
		topsort(i);

	/*for (int i : ts)
		printf("%I32d ", i);
	printf("\n");*/

	forn(i, 0, n)
		was[i] = false;
	comp.resize(n);
	cnt = 0;
	form(i, n, 0) {
		if (!was[ts[i]]) {
			cnt++;
			component(ts[i]);
		}
	}

	/*printf("%d\n", cnt);
	forn(i, 0, n)
		printf("%d ", comp[i]);
	printf("\n");*/
	
	vector<set<int>> newgraph(cnt);
	forn(i, 0, n) {
		for (int j : graph[i]) {
			if (comp[i] != comp[j])
				newgraph[comp[i] - 1].insert(comp[j] - 1);
		}
	}

	/*forn(i, 0, cnt) {
		printf("%d: ", i);
		for (int j : newgraph[i])
			printf("%d ", j);
		printf("\n");
	}*/

	int sum = 0;
	forn(i, 0, cnt) {
		sum += newgraph[i].size();
	}

	printf("%d", sum);
	
	return 0;
}
