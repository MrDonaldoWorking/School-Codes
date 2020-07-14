#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <queue>
#include <fstream>
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
	//ifstream in("78.in");
	//ofstream out("78.out");
	int n;
	cin >> n;
	vector<int> b(n);
	forn(i, 0, n)
		cin >> b[i];
	vector<vector<int>> a(n, vector<int>());
	forn(i, 0, n) {
		int y;
		cin >> y;
		forn(j, 0, y) {
			int z;
			cin >> z;
			a[i].pb(z - 1);
		}
	}
	/*forn(i, 0, n) {
	forn(j, 0, a[i].size())
	cout << a[i][j] << ' ';
	cout << endl;
	}*/
	queue<int> q;
	q.push(0);
	vector<bool> used(n, false);
	used[0] = true;
	while (!q.empty()) {
		for (int i : a[q.front()]) {
			//used[i] = true;
			if (!used[i])
				q.push(i);
			used[i] = true;
		}
		q.pop();
	}
	ll s = 0;
	forn(i, 0, n)
		//cout << answer[i] << ' ';
		if (used[i])
			s += b[i];
	cout << s;
	return 0;
}