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
	vector<vector<int>> dinamic(n + 1, vector<int>(m + 1, 0));
	forn(i, 1, n + 1)
		forn(j, 1, m + 1)
		cin >> dinamic[i][j];
	int maxlength = 0;
	forn(i, 1, n + 1)
		forn(j, 1, m + 1)
		if (dinamic[i][j]) {
			dinamic[i][j] = min(min(dinamic[i - 1][j - 1], dinamic[i][j - 1]), dinamic[i - 1][j]) + 1;
			maxlength = max(maxlength, dinamic[i][j]);
		}
	cout << maxlength;
	return 0;
}