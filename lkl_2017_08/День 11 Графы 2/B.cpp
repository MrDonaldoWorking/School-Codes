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

struct edge {
	int to;
	int w;
};

int main() {
	freopen("distance.in", "r", stdin);
	freopen("distance.out", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);

	int start, finish;
	scanf("%d%d", &start, &finish);

	vector<vector<edge>> graph(n);
	forn(i, 0, m) {
		int from, to, weight;
		cin >> from >> to >> weight;
		graph[from - 1].push_back({ to - 1, weight });
		graph[to - 1].push_back({ from - 1, weight });
	}

	set<pair<int, int>> distance;
	vector<int> length(n, INF);
	length[start - 1] = 0;
	distance.insert({ 0, start - 1 });
	while (!distance.empty()) {
		int v = distance.begin()->second;
		distance.erase(distance.begin());

		for (edge e : graph[v]) {
			if (length[e.to] > length[v] + e.w) {
				distance.erase({ length[e.to], e.to });
				length[e.to] = length[v] + e.w;
				distance.insert({ length[e.to], e.to });
			}
		}
	}

	printf("%d", (length[finish - 1] == INF ? -1 : length[finish - 1]));

	return 0;
}