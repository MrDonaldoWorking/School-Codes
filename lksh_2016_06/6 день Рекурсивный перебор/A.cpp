#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
typedef long long ll;
typedef unsigned long long ull;
#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
#define fi first
#define se second
#define pb push_back
#define po pop_back
using namespace std;

vector<int> a;

void rec(int x) {
	if (x == 0) {
		forn(i, 0, a.size())
			cout << a[i] << ' ';
		cout << endl;
		return;
	}
	a.pb(0);
	rec(x - 1);
	a.po();
	if (a.empty() || a.back() == 0) {
		a.pb(1);
		rec(x - 1);
		a.po();
	}
}

int main() {
	//ifstream in("reverse.in");
	//ofstream out("reverse.out");
	int n;
	cin >> n;
	rec(n);
	return 0;
}