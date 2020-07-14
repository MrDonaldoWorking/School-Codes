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

vector<int> p;

int dsu_get(int v) {
	return (v == p[v]) ? v : (p[v] = dsu_get(p[v]));
}

void dsu_unite(int a, int b) {
	a = dsu_get(a);
	b = dsu_get(b);
	if (rand() & 1)
		swap(a, b);
	if (a != b)
		p[a] = b;
}

struct edge {
	int from;
	int to;
	int w;

	bool operator <(const edge &e) const {
		return w < e.w;
	}
};

int main() {
	freopen("spantree2.in", "r", stdin);
	freopen("spantree2.out", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);

	vector<edge> graph;
	forn(i, 0, m) {
		int from, to, weight;
		scanf("%d%d%d", &from, &to, &weight);

		graph.push_back({ from - 1, to - 1, weight });
		//graph.push_back({ to, from, weight });
	}

	sort(all(graph));

	/*for (auto i : graph) {
		printf("%d %d %d\n", i.from, i.to, i.w);
	}
	printf("\n");*/

	p.resize(n);
	forn(i, 0, n)
		p[i] = i;

	int cost = 0;
	vector<pair<int, int>> res;
	forn(i, 0, m) {
		int a = graph[i].from;
		int b = graph[i].to;
		int l = graph[i].w;

		if (dsu_get(a) != dsu_get(b)) {
			cost += l;
			res.push_back({ graph[i].from, graph[i].to });
			dsu_unite(a, b);
		}
	}

	printf("%d", cost);
	/*for (auto i : res) {
		printf("%d %d\n", i.first, i.second);
	}*/

	return 0;
}