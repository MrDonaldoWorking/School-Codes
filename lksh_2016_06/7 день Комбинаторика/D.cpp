#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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
	int n, k;
	cin >> k >> n;
	vector<int> a(n);
	forn(i, 0, n)
		cin >> a[i];
	int i = n - 1;
	while (i > 0 && a[i] == k - n + 1 + i)
		i--;
	if (i == 0 && a[i] == k - n + 1) 
		cout << 0;
	else {
		a[i]++;
		//cout << i << endl;
		forn(j, 1, n - i)
			a[i + j] = a[i] + j;
		forn(i, 0, n)
			cout << a[i] << ' ';
	}
	return 0;
}