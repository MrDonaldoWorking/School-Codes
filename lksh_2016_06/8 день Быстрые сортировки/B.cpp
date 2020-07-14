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

vector<int> lbuf, rbuf;
const int MAX_ELEMENT = INT_MAX;
int inverse = 0;

void merge(vector<int> &a, int left, int right) {
	if (right - left <= 1)
		return;
	int mid = (left + right) / 2;
	merge(a, left, mid);
	merge(a, mid, right);
	lbuf.assign(a.begin() + left, a.begin() + mid);
	rbuf.assign(a.begin() + mid, a.begin() + right);
	lbuf.pb(MAX_ELEMENT);
	rbuf.pb(MAX_ELEMENT);
	int lp = 0, rp = 0;
	forn(i, left, right) {
		if (lbuf[lp] <= rbuf[rp]) {
			a[i] = lbuf[lp];
			lp++;
		}
		else {
			a[i] = rbuf[rp];
			rp++;
			inverse += lbuf.size() - lp - 1;
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> sample(n);
	forn(i, 0, n)
		cin >> sample[i];
	merge(sample, 0, n);
	/*forn(i, 0, n)
		cout << sample[i] << ' ';
	*/
	cout << inverse;
	return 0;
}