#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
typedef long long ll;
#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
#define pb push_back
#define po pop_back
#define fi first
#define se second
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	forn(i, 0, n)
		cin >> a[i];
	int i = n - 2;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	while (i >= 0 && a[i] < a[i + 1]) 
		i--;
	if (i == -1 && a[i + 1] < a[i + 2])
		form(i, n, 0)
			cout << i + 1 << ' ';
	else {
		int	j = n - 1;
		while (a[j] > a[i])
			j--;
		swap(a[j], a[i]);
		reverse(a.begin() + i + 1, a.end());
		forn(i, 0, n)
			cout << a[i] << ' ';
	}
	return 0;
}