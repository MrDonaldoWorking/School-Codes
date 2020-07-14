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

vector<vector<int>> graph;
vector<int> color;
vector<int> answer;
const int WHITE = 0, GREY = 1, BLACK = 2;

void dfs(int v) {
	if (color[v] == GREY) {
		printf("-1");
		exit(0);
	}

	if (color[v] == BLACK)
		return;

	color[v] = GREY;

	for (int u : graph[v])
		dfs(u);

	color[v] = BLACK;

	answer.push_back(v);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);

	graph.resize(n);
	forn(i, 0, m) {
		int x, y;
		scanf("%d%d", &x, &y);

		graph[x - 1].push_back(y - 1);
	}

	color.resize(n, WHITE);

	forn(i, 0, n)
		dfs(i);

	form(i, n, 0)
		printf("%d ", answer[i] + 1);

	return 0;
}