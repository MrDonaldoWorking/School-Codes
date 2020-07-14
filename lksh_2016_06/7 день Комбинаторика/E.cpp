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

vector<int> a;
vector<vector<int>> c;

void gen(int number, int length, int index, int lower) {
	if (length == 0) return;
	if (index >= c[number - 1][length - 1])
		gen(number - 1, length, index - c[number - 1][length - 1], lower + 1);
	else {
		a.pb(lower);
		gen(number - 1, length - 1, index, lower + 1);
	}
}
int main() {
	int n, k, m;
	cin >> n >> k >> m;
	c.resize(n, vector<int>(k, 0));
	forn(i, 0, n)
		c[i][0] = 1;
	forn(i, 1, n)
		forn(j, 1, k)
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	gen(n, k, m, 1);
	forn(i, 0, a.size())
		cout << a[i] << ' ';
	return 0;
}