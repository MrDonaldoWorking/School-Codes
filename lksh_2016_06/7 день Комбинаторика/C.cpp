#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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
	int n, k;
	cin >> n >> k;
	vector<vector<ll>> c(n + 1, vector<ll>(k + 1, 0));
	forn(i, 0, n)
		c[i][0] = 1;
	forn(i, 1, n + 1)
		forn(j, 1, k + 1)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	cout << c[n][k];
	return 0;
}