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
	vector<int> a(n);
	a[0] = 2;
	if (n > 1) a[1] = 4;
	if (n > 2) a[2] = 7;
	forn(i, 3, n) {
		a[i] = a[i - 1] + a[i - 2] + a[i - 3];
	}
	cout << a[n - 1];
	return 0;
}