#include <iostream>
#include <vector>
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

int n, answer = 0;
vector<pair<int, int>> knight;

void go(int i) {
	if (i == n) {
		answer++;
		return;
	}
	forn(j, 0, n) {
		bool can = true;
		forn(k, 0, knight.size()) {
			if (abs(knight[k].fi - i) == abs(knight[k].se - j) || knight[k].fi == i || knight[k].se == j) {
				can = false;
			}
		}
		if (can) {
			knight.pb({ i, j });
			go(i + 1);
			knight.po();
		}
	}
}

int main() {
	cin >> n;
	go(0);
	cout << answer;
}