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
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<ll>> a(n + 4, vector<ll>(m + 4, 0));
	a[2][2] = 1;
	forn(x, 3, n + 2) {
		int save = x, y = 2;
		while (x > 1 && y < m + 2) {
			a[x][y] = a[x - 1][y - 2] + a[x - 2][y - 1] + a[x + 1][y - 2] + a[x - 2][y + 1];
			x--;
			y++;
		}
		x = save;
	}
	forn(y, 3, m + 2) {
		int save = y, x = n + 1;
		while (x > 1 && y < m + 2) {
			a[x][y] = a[x - 1][y - 2] + a[x - 2][y - 1] + a[x + 1][y - 2] + a[x - 2][y + 1];
			x--;
			y++;
		}
		y = save;
	}
	cout << a[n + 1][m + 1];
	return 0;
}