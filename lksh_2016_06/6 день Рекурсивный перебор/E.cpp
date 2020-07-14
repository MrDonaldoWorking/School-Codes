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

void rec(int n, int k) {
	if (k == 0) {
		forn(i, 0, a.size())
			cout << a[i] << ' ';
		cout << endl;
		return;
	}
	if (n > k)
		rec(n - 1, k);
	a.pb(n);
	rec(n - 1, k - 1);
	a.po();
}

int main() {
	//ifstream in("reverse.in");
	//ofstream out("reverse.out");
	int n, m;
	cin >> n >> m;
	rec(m, n);
	return 0;
}