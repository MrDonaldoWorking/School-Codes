#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <queue>
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
	int n, x = 0;
	cin >> n;
	vector<vector<bool>> a(n, vector<bool>(n));
	vector<int> b(n, -1);
	int y;
	forn(i, 0, n)
		forn(j, 0, n) {
		cin >> y;
		if (y == 1)
			a[i][j] = true;
			x += a[i][j];
		}
	queue<int> q;
	q.push(0);
	b[0] = 0;
	while (!q.empty()) {
		forn(i, 0, n)
			if (a[q.front()][i] == true && b[i] == -1) {
				b[i] = b[q.front()] + 1;
				q.push(i);
			}
		q.pop();
	}
	bool not_tree = false;
	forn(i, 0, n)
		if (b[i] == -1)
			not_tree = true;
	if (not_tree || x != 2 * n - 2)
		cout << "NO";
	else
		cout << "YES";
	return 0;
}