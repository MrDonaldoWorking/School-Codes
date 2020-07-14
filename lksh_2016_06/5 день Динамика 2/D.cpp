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
	int x, y, z;
	cin >> x >> y >> z;
	vector<int> a(x + 1);
	forn(i, 1, x + 1) 
		cin >> a[i];
	vector<int> b(y + 1);
	forn(i, 1, y + 1) 
		cin >> b[i];
	vector<int> c(z + 1);
	forn(i, 1, z + 1)
		cin >> c[i];
	vector<vector<vector<int>>> dinamic(x + 1, vector<vector<int>>(y + 1, vector<int>(z + 1)));
	forn(i, 1, x + 1) 
		forn(j, 1, y + 1) 
			forn(k, 1, z + 1) {
				if (a[i] == b[j] && b[j] == c[k])
					dinamic[i][j][k] = dinamic[i - 1][j - 1][k - 1] + 1;
				else 
					dinamic[i][j][k] = max(max(dinamic[i - 1][j][k], dinamic[i][j - 1][k]), dinamic[i][j][k - 1]);
			}
	cout << dinamic[x][y][z];
	return 0;
}