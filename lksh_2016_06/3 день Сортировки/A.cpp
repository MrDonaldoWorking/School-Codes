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
#define fi first
#define se second
#define pb push_back
#define po pop_back
using namespace std;

int main() {
	ll n;
	int m;
	cin >> n >> m;
	vector<ll> a(1001, 0);
	ll x;
	forn(i, 0, m) {
		cin >> x;
		a[x - n + 1000]++;
	}
	form(i, 1001, 0) {
		forn(j, 0, a[i])
			cout << i + n - 1000 << ' ';
	}
	return 0;
}