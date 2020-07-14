#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <climits>
typedef long long ll;
typedef unsigned long long ull;
#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> d(n);
	fill(d.begin(), d.end(), 1);
	forn(i, 0, n)
		cin >> a[i];
	forn(i, 0, n) {
		forn(j, 0, i) {
			if (a[i] % a[j] == 0)
				d[i] = max(d[i], d[j] + 1);
		}
	}
	cout << *max_element(d.begin(), d.end());
	return 0;
}