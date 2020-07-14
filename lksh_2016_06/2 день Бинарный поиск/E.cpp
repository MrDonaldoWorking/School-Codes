#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
typedef long long ll;
#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
using namespace std;

double eps = 1e-10;

double search(double x) {
	double l = -10, r = 10, m;
	for (int i = 0; i < 100; i++) {
		m = (l + r) / 2;
		if (cos(m) - x * m < eps) 
			r = m;
		else 
			l = m;
	}
	return l;
}

int main() {
	//ifstream in("reverse.in");
	//ofstream out("reverse.out");
	double a;
	cin >> a;
	cout.precision(10);
	cout << fixed;
	cout << search(a);
	return 0;
}