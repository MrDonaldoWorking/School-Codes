#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
typedef long long ll;
typedef unsigned long long ull;
#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
#define pb push_back
#define po pop_back
#define fi first
#define se second
using namespace std;

vector<vector<int>> graph;
vector<int> color;
const int WHITE = 0, GREY = 1, BLACK = 2;

void dfs_answer(int v) {
	if (color[v] != GREY)
		return;
	color[v] = BLACK;
	cout << v + 1 << ' ';
	for (int u : graph[v])
		dfs_answer(u);
}

void dfs(int v) {
	if (color[v] == GREY) {
		cout << "YES" << endl;
		dfs_answer(v);
		exit(0);
	}
	if (color[v] == BLACK)
		return;
	color[v] = GREY;
	for (int u : graph[v])
		dfs(u);
	color[v] = BLACK;
}

int main() {
	int n, m;
	cin >> n >> m;
	graph.resize(n, vector<int>());
	forn(i, 0, m) {
		int x, y;
		cin >> x >> y;
		graph[x - 1].pb(y - 1);
	}
	color.resize(n, WHITE);
	forn(i, 0, n)
		dfs(i);
	cout << "NO";
	return 0;
}