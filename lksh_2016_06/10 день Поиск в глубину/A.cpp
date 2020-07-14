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

void dfs(int v, int k) {
	if (color[v]) 
		return;
	color[v] = k;
	for (int u : a[v])
		dfs(u, k);
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
	int k = 0;
	color.resize(n, 0);
	forn(i, 0, n)
		if (!color[i]) {
			k++;
			dfs(i, k);
		}
	/*forn(i, 0, n) {
		cout << i + 1 << "    ";
		forn(j, 0, a[i].size())
			cout << a[i][j] + 1 << ' ';
		cout << endl;
	}
	cout << endl;*/
	cout << k << endl;
	vector<vector<int>> answer(k, vector<int>());
	forn(i, 0, n)
		answer[color[i] - 1].pb(i);
	forn(i, 0, k) {
		cout << answer[i].size() << endl;
		forn(j, 0, answer[i].size())
			cout << answer[i][j] + 1 << ' ';
		cout << endl;
	}
	return 0;
}