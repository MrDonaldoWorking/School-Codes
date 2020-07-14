#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
typedef unsigned long long ull;
typedef long long ll;
#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
using namespace std;

ull search(ull x, ull y, ull z) {
	ull l = 0, r = 2e18, m;
	while (r - l > 1) {
		m = (l + r) / 2;
		if ((m / x) * (m / y) >= z)
			r = m;
		else
			l = m;
	}
	return r;
}

int main() {
	//ifstream in("reverse.in");
	//ofstream out("reverse.out");
	ull w, h, n;
	cin >> w >> h >> n;
	cout << search(w, h, n);
	return 0;
}