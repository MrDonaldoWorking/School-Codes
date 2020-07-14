#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
typedef long long ll;
typedef unsigned long long ull;
#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
#define pb push_back
#define po pop_back
#define fi first
#define se second
using namespace std;

ll n, s;
vector<int> a;
vector<int> ans;
bool more_that = false;

void answer() {
	int k = 0;
	forn(i, 0, n)
		k += ans[i];
	cout << k << endl;
	forn(i, 0, n)
		forn(j, 0, ans[i])
		cout << a[i] << ' ';
}

void search(int i, ll sum) {
	if (sum == s) {
		answer();
		exit(0);
	}
	if (sum > s && i == n)
		more_that = true;
	if (i == n)
		return;
	forn(j, 0, 3) {
		ans[i] = j;
		search(i + 1, sum + a[i] * ans[i]);
	}
	ans[i] = 0;
}

int main() {
	cin >> s >> n;
	a.resize(n);
	forn(i, 0, n)
		cin >> a[i];
	sort(a.begin(), a.end());
	ans.resize(n, 0);
	forn(i, 0, 3) {
		ans[0] = i;
		search(1, a[0] * ans[0]);
	}
	cout << more_that - 1;
	return 0;
}