#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <climits>
typedef long long ll;
typedef unsigned long long ull;
#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
#define fi first
#define se second
using namespace std;

vector<vector<int>> a;
vector<pair<int, int>> b;

void road(int x, int y) {
	b.push_back({ x , y });
	if (x == 0 && y == 0) 
		return;
	if (x == 0) 
		road(x, y - 1);
	if (y == 0) 
		road(x - 1, y);
	if (x > 0 && y > 0) {
		if (a[x - 1][y] > a[x][y - 1])
			road(x, y - 1);
		else
			road(x - 1, y);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	a.resize(n, vector<int>(m));
	forn(i, 0, n)
		forn(j, 0, m)
		cin >> a[i][j];
	forn(i, 0, n) {
		forn(j, 0, m) {
			if (i == 0 && j == 0) 
				continue;
			if (i == 0 && j > 0) 
				a[i][j] += a[i][j - 1];
			if (i > 0 && j == 0) 
				a[i][j] += a[i - 1][j];
			if (i > 0 && j > 0) 
				a[i][j] += min(a[i - 1][j], a[i][j - 1]);
		}
	}
	cout << a[n - 1][m - 1] << endl;
	road(n - 1, m - 1);
	cout << b.size() << endl;
	form(i, b.size(), 0)
		cout << b[i].fi + 1 << ' ' << b[i].se + 1 << endl;
	return 0;
}