#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
typedef long long ll;
typedef unsigned long long ull;
#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
using namespace std;

/*int n, m;
vector<vector<int>> a;

void dp(int x, int y) {
if (x < 0 || y < 0) return;
if (x >= n || y >= m) return;
//cout << x << ' ' << y << endl;
a[x][y]++;
dp(x + 2, y + 1);
dp(x + 1, y + 2);
dp(x - 1, y + 2);
dp(x + 2, y - 1);
}

int main() {
//ifstream in("reverse.in");
//ofstream out("reverse.out");
cin >> n >> m;
a.resize(n, vector<int>(m));
//dp(0, 0);

/*forn(i, 0, n) {
forn(j, 0, m) {
cout << a[i][j] << ' ';
}
cout << endl;
}
cout << a[n - 1][m - 1];
return 0;
}*/
int main() {
	int n;
	cin >> n;
	vector<vector<int>> a(10, vector<int>(n));
	forn(i, 1, 10)
		a[i][0] = 1;
	forn(i, 1, n) {
		a[0][i] = a[0][i - 1] + a[1][i - 1];
		a[9][i] = a[9][i - 1] + a[8][i - 1];
		forn(j, 1, 9)
			a[j][i] = a[j][i - 1] + a[j - 1][i - 1] + a[j + 1][i - 1];
	}
	ll s = 0;
	forn(i, 0, 10)
		s += a[i][n - 1];
	cout << s;
	return 0;
}