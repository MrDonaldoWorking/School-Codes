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

vector<vector<int>> graph;
vector<int> match;
vector<bool> used;

bool kuhn(int v) {
	if (used[v])
		return false;
	used[v] = true;

	for (int to : graph[v]) {
		if (match[to] == -1 || kuhn(match[to])) {
			match[to] = v;
			return true;
		}
	}
	return false;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);

	graph.resize(n);
	forn(i, 0, n) {
		forn(j, 0, m) {
			int x;
			scanf("%d", &x);
			if (x == 1)
				graph[i].push_back(j);
		}
	}

	match.resize(m, -1);
	forn(v, 0, n) {
		used.assign(n, false);
		kuhn(v);
	}

	forn(i, 0, m) {
		printf("%d ", match[i] + 1);
	}

	return 0;
}