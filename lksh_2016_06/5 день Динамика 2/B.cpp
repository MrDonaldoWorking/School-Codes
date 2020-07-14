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

vector<int> a;
vector<vector<bool>> can;
vector<bool> answer;

void inv_answer(int n, int s) {
	if (n == 0)
		return;
	if (can[n - 1][s]) {
		answer.pb(false);
		inv_answer(n - 1, s);
	}
	else {
		answer.pb(true);
		inv_answer(n - 1, s - a[n - 1]);
	}
	return;
}

int main() {
	int n;
	cin >> n;
	int s = 0;
	a.resize(n);
	forn(i, 0, n) {
		cin >> a[i];
		s += a[i];
	}
	s /= 2;
	can.resize(n + 1, vector<bool>(s + 1, false));
	can[0][0] = true;
	forn(i, 1, n + 1)
		forn(j, 0, s + 1) {
		can[i][j] = can[i - 1][j];
		if (j >= a[i - 1])
			can[i][j] = can[i][j] || can[i - 1][j - a[i - 1]];
	}
	inv_answer(n, s);
	form(i, n, 0) {
		if (answer[i]) cout << '+';
		else cout << '-';
	}
	return 0;
}