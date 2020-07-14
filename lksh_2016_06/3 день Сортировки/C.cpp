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

struct q {
	int numerator, denominator;
	char delimiter;
	bool operator < (const q& q1) {
		if (q1.denominator * numerator == denominator * q1.numerator)
			return numerator < q1.numerator;
		return q1.denominator * numerator < denominator * q1.numerator;
	}
};

double x, y;
vector<q> a;

int main() {
	//ifstream in("reverse.in");
	//ofstream out("reverse.out");
	int n;
	cin >> n;
	a.resize(n);
	forn(i, 0, n)
		cin >> a[i].numerator >> a[i].delimiter >> a[i].denominator;
	sort(a.begin(), a.end());
	forn(i, 0, n)
		cout << a[i].numerator << a[i].delimiter << a[i].denominator << endl;
	return 0;
}