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
	vector<int> length(n, INF);
	length[start - 1] = 0;
	vector<bool> was(n, false);
	vector<int> previous(n, 0);
	forn(i, 0, n) {
		int minum = INF, v = INF;
		forn(j, 0, n)
			if (!was[j] && length[j] < minum) {
				minum = length[j];
				v = j;
			}
		if (v == INF)
			break;
		was[v] = true;
		for (edge e : graph[v]) {
			if (length[e.to] > length[v] + e.w) {
				previous[e.to] = v;
				length[e.to] = length[v] + e.w;
			}
		}
	}
	/*forn(i, 0, n)
	cout << previous[i] + 1 << ' ';
	cout << endl;*/
	vector<int> answer;
	cout << length[finish - 1] << endl;
	for (int i = finish - 1; i != start - 1; i = previous[i])
		answer.pb(previous[i] + 1);
	form(i, answer.size(), 0)
		cout << answer[i] << ' ';
	cout << finish;
	return 0;
}