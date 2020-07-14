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

vector<vector<int>> graph;
vector<int> tin;
vector<int> tout;

void topsort(int v, int &d) {
	tin[v] = d;
	d++;

	for (int u : graph[v])
		topsort(u, d);

	tout[v] = d;
	d++;
}

int main() {
	freopen("ancestor.in", "r", stdin);
	freopen("ancestor.out", "w", stdout);

	int n;
	scanf("%d", &n);

	graph.resize(n);
	int root;
	forn(i, 0, n) {
		int x;
		scanf("%d", &x);
		x--;

		if (x >= 0)
			graph[x].push_back(i);
		else
			root = i;
	}

	tin.resize(n);
	tout.resize(n);

	int d = 0;
	topsort(root, d);

	int m;
	scanf("%d", &m);
	forn(i, 0, m) {
		int from, to;
		scanf("%d%d", &from, &to);
		from--;
		to--;

		if (tin[from] < tin[to] && tout[to] < tout[from])
			printf("1\n");
		else
			printf("0\n");
	}

	return 0;
}