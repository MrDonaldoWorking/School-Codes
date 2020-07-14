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

vector<vector<int>> a;

int main() {
	//ifstream in("reverse.in");
	//ofstream out("reverse.out");
	int n, m;
	cin >> n >> m;
	a.resize(n + 2, vector<int>(m + 2));
	forn(i, 0, n + 2) {
		forn(j, 0, m + 2) {
			if (i < 2 || j < 2) 
				a[i][j] = 0;
			else {
				if (i == 2 && j == 2)
					a[i][j] = 1;
				else
					a[i][j] = a[i - 2][j - 1] + a[i - 1][j - 2]; //+ a[i + 1][j - 2] + a[i - 2][j + 1];
			}
		}
	}
	cout << a[n + 1][m + 1];
	return 0;
}