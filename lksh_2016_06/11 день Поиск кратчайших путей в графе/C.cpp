#include <iostream>
#include <vector>
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
vector<vector<int>> previous;
vector<int> answer;

void out(int start, int finish) {
	if (start == finish) {
		cout << answer.size() + 1 << endl;
		cout << start + 1 << ' ';
		form(i, answer.size(), 0)
			cout << answer[i] + 1 << ' ';
		return;
	}
	answer.pb(finish);
	out(start, previous[start][finish]);
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> graph(n, vector<int>(n));
	previous.resize(n, vector<int>(n));
	forn(i, 0, n)
		forn(j, 0, n) {
		cin >> graph[i][j];
		previous[i][j] = i;
		if (graph[i][j] == 1e5)
			graph[i][j] = INF;
	}
	forn(k, 0, n)
		forn(i, 0, n)
		forn(j, 0, n) {
		if (graph[i][k] < INF && graph[k][j] < INF && graph[i][j] > graph[i][k] + graph[k][j]) {
			graph[i][j] = graph[i][k] + graph[k][j];
			previous[i][j] = previous[k][j];
		}
		if (i == j && graph[i][j] < 0) {
			cout << "YES" << endl;
			out(i, previous[i][j]);
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
/*
3
0 1 -1
-1 0 1
1 -1 0
*/