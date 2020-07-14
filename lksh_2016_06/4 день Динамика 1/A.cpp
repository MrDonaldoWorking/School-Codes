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

vector<int> a;

int sum(int z, int x) {
	int s = 0;
	forn(i, 0, x)
		s += a[z - i - 1];
	return s;
}

int main() {
	//ifstream in("reverse.in");
	//ofstream out("reverse.out");
	int n, k;
	cin >> n >> k;
	a.resize(n);
	a[0] = 1;
	a[1] = 1;
	forn(i, 2, n) {
		a[i] = sum(i, min(i, k));
		//cout << a[i] << ' ' << i - 1 << endl;
	}
	cout << a[n - 1];
	return 0;
}