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

vector<vector<int>> a;
vector<int> color;
vector<bool> was;
bool answer = true;

void dfs(int v, int k) {
	if (was[v]) {
		if (color[v] == k && answer)
			answer = true;
		else
			answer = false;
		return;
	}
	color[v] = k;
	was[v] = true;
	for (int u : a[v])
		dfs(u, 3 - k);
}

int main() {
	int n, m;
	cin >> n >> m;
	a.resize(n, vector<int>());
	forn(i, 0, m) {
		int x, y;
		cin >> x >> y;
		a[x - 1].pb(y - 1);
		a[y - 1].pb(x - 1);
	}
	/*forn(i, 0, n) {
		forn(j, 0, a[i].size())
			cout << a[i][j] + 1 << ' ';
		cout << endl;
	}*/
	color.resize(n, 1);
	was.resize(n, false);
	forn(i, 0, n) {
		/*forn(j, 0, n)
			cout << color[j] << ' ';
		cout << endl;
		forn(j, 0, n)
			cout << was[j] << ' ';
		cout << endl;*/
		dfs(i, color[i]);
		if (!answer) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
/*
7 9
1 5
1 4
5 2
2 4
4 3
3 7
7 6
2 3
2 6
*/