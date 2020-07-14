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

int main() {
	int n;
	cin >> n;
	vector<vector<int>> graph(n, vector<int>(n, INF));
	forn(i, 0, n)
		forn(j, 0, n)
			cin >> graph[i][j];
	forn(k, 0, n)
		forn(i, 0, n)
			forn(j, 0, n)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
	forn(i, 0, n) {
		forn(j, 0, n)
			cout << graph[i][j] << ' ';
		cout << endl;
	}
	return 0;
}