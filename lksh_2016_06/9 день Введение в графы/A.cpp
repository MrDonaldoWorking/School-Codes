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
	int n;
	cin >> n;
	int m;
	vector<vector<int>> a(n, vector<int>());
	vector<vector<int>> b(n, vector<int>());
	forn(i, 0, n) {
		cin >> m;
		int x;
		forn(j, 0, m) {
			cin >> x;
			a[i].pb(x);
			b[x - 1].pb(i + 1);
		}
	}
	cout << n << endl;
	forn(i, 0, n) {
		cout << b[i].size() << ' ';
		forn(j, 0, b[i].size())
			cout << b[i][j] << ' ';
		cout << endl;
	}
	return 0;
}