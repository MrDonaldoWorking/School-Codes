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

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);

	vector<vector<int>> graph(n, vector<int>(n));
	forn(i, 0, n) {
		forn(j, 0, n) {
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == -1)
				graph[i][j] = INF;
		}
	}

	forn(k, 0, n) {
		forn(i, 0, n) {
			forn(j, 0, n) {
				amin(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	int ans = 0;
	forn(i, 0, n) {
		forn(j, 0, n) {
			if (i != j && graph[i][j] < INF)
				amax(ans, graph[i][j]);
		}
	}

	printf("%d", ans);

	return 0;
}