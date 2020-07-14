#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <set>
typedef long long ll;
typedef unsigned long long ull;
#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
#define pb push_back
#define po pop_back
#define fi first
#define se second
using namespace std;

const int INF = 2147483647;

struct edge {
	int to;
	int w;
};

int main() {
	int n, m;
	cin >> n >> m;
	int start, finish;
	cin >> start >> finish;
	vector<vector<edge>> graph(n, vector<edge>());
	forn(i, 0, m) {
		int from, to, weight;
		cin >> from >> to >> weight;
		graph[from - 1].pb({ to - 1, weight });
		graph[to - 1].pb({ from - 1, weight });
	}
	set<pair<int, int>> distance;
	vector<int> length(n, INF);
	length[start - 1] = 0;
	distance.insert({ 0, start - 1 });
	while (!distance.empty()) {
		int v = distance.begin() -> se;
		distance.erase(distance.begin());
		for (edge e : graph[v]) {
			if (length[e.to] > length[v] + e.w) {
				distance.erase({ length[e.to], e.to });
				length[e.to] = length[v] + e.w;
				distance.insert({ length[e.to], e.to });
			}
		}
	}
	//cout << length[finish - 1] == INF ? -1 : length[finish - 1];
	if (length[finish - 1] == INF)
		cout << -1;
	else
		cout << length[finish - 1];
	return 0;
}