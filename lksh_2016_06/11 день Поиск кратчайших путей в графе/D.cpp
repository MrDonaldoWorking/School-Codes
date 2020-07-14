#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
#define sz(a) (int)a.size()

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAILRU = 1;
const int YANDEX = 2;
const int INF = 1e9;
//ifstream in("input.txt");
//ofstream out("output.txt");

struct edge {
	int to;
	int w;
};

int main() {
	int n, m;
	cin >> n >> m;

	int start = n, finish = n + 1;

	vector<vector<edge>> graph(n + 2, vector<edge>());
	forn(i, 0, n) {
		int x;
		cin >> x;
		
		if (x == MAILRU) {
			graph[start].push_back({ i, 0 });
			graph[i].push_back({ start, 0 });
		}
		if (x == YANDEX) {
			graph[finish].push_back({ i, 0 });
			graph[i].push_back({ finish, 0 });
		}
	}

	forn(i, 0, m) {
		int from, to, weight;
		cin >> from >> to >> weight;
		graph[from - 1].push_back({ to - 1, weight });
		graph[to - 1].push_back({ from - 1, weight });
	}

	vector<int> distance(n + 2, INF);
	distance[start] = 0;
	vector<bool> was(n + 2, false);
	vector<int>previous(n + 2, 0);
	forn(i, 0, n + 2)
		previous[i] = i;

	forn(i, 0, n + 2) {
		int min_ = INF, vertex = INF;
		forn(j, 0, n + 2)
			if (!was[j] && distance[j] < min_) {
				min_ = distance[j];
				vertex = j;
			}

		if (vertex == INF)
			break;
		was[vertex] = true;

		for (edge e : graph[vertex])
			if (distance[e.to] > distance[vertex] + e.w) {
				previous[e.to] = vertex;
				distance[e.to] = distance[vertex] + e.w;
			}
	}

	int result = finish;
	forn(i, 0, n + 2) {
		if (previous[result] == start)
			break;
		result = previous[result];
	}

	if (previous[result] != start || distance[finish] == INF) {
		cout << -1;
		return 0;
	}

	cout << result + 1 << ' ' << previous[finish] + 1 << ' ' << distance[finish];

	/*cout << endl;
	forn(i, 0, n + 2)
		cout << i << ' ' << previous[i] << endl;*/
	/*forn(i, 0, n + 2)
		cout << i << ' ' << distance[i] << endl;*/

	/*cout << endl;
	forn(i, 0, n + 2) {
		cout << i << endl;
		for (auto j : graph[i])
			cout << j.to << ' ' << j.w << endl;
	}*/
	
	return 0;
}