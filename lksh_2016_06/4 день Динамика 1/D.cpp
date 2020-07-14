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
	vector<int> a(n + 1);
	vector<int> b(n + 1);
	a[0] = 0;
	forn(i, 2, n + 1) {
		a[i] = a[i - 1] + 1;
		b[i] = 1;
		if (i % 2 == 0 && a[i] > a[i / 2] + 1) {
			a[i] = a[i / 2] + 1;
			b[i] = 2;
		}
		if (i % 3 == 0 && a[i] > a[i / 3] + 1) {
			a[i] = a[i / 3] + 1;
			b[i] = 3;
		}
	}
	cout << a[n] << endl;
	/*forn(i, 1, n + 1) {
	cout << a[i] << ' ' << b[i] << ' ' << i << endl;
	}*/
	//cout << n << ' ';
	int k = 0, m = n;
	vector<int>c(a[n]);
	while (n > 1) {
		c[k] = n;
		k++;
		switch (b[n]) {
		case 1:
			n--;
			break;
		case 2:
			n /= 2;
			break;
		case 3:
			n /= 3;
			break;
		}
	}
	c.push_back(1);
	form(i, a[m] + 1, 0) {
		cout << c[i] << ' ';
	}
	return 0;
}