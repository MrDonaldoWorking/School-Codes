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

static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

struct edge {
	int to;
	ld w;
};

const double EPS = 1e-6;

int main() {
	freopen("danger.in", "r", stdin);
	freopen("danger.out", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);

	int start, finish;
	scanf("%d%d", &start, &finish);

	vector<vector<edge>> graph(n);
	forn(i, 0, m) {
		int from, to, weight;
		scanf("%d%d%d", &from, &to, &weight);

		graph[from - 1].push_back({ to - 1, (ld)1 - (ld)weight / 100 });
		graph[to - 1].push_back({ from - 1, (ld)1 - (ld)weight / 100 });
	}

	vector<ld> length(n, 0);
	length[start - 1] = 1;
	vector<bool> was(n, false);
	forn(i, 0, n) {
		ld maxum = -1;
		int v = INF;
		forn(j, 0, n)
			if (!was[j] && length[j] > maxum + EPS) {
				maxum = length[j];
				v = j;
			}

		if (v == INF)
			break;

		was[v] = true;

		for (edge e : graph[v]) {
			if (length[v] * e.w > length[e.to] + EPS) {
				length[e.to] = length[v] * e.w;
			}
		}
	}

	printf("%.9llf", (ld)1 - length[finish - 1]);

	return 0;
}