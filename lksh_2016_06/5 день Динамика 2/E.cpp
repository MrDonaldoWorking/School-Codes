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
	string a, b;
	cin >> a >> b;
	vector<vector<int>> dinamic(5001, vector<int>(5001));
	int saving = 0, point;
	forn(i, 0, a.size()) {
		forn(j, 0, b.size()) {
			if (a[i] == b[j])
				dinamic[i + 1][j + 1] = dinamic[i][j] + 1;
			else
				dinamic[i + 1][j + 1] = 0;
			if (saving < dinamic[i + 1][j + 1]) {
				saving = dinamic[i + 1][j + 1];
				point = i - saving + 1;
			}
		}
	}
	forn(i, 0, saving)
		cout << a[i + point];
	return 0;
}