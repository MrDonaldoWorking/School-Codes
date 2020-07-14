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

void merge(vector<int> &sample, int left, int right) {
	if (right - left <= 1)
		return;
	int mid = (left + right) / 2;
	merge(sample, left, mid);
	merge(sample, mid, right);
	lbuf.assign(sample.begin() + left, sample.begin() + mid);
	rbuf.assign(sample.begin() + mid, sample.begin() + right);
	lbuf.pb(MAX_ELEMENT);
	rbuf.pb(MAX_ELEMENT);
	int lp = 0, rp = 0;
	forn(i, left, right) {
		if (lbuf[lp] <= rbuf[rp]) {
			sample[i] = lbuf[lp];
			lp++;
		}
		else {
			sample[i] = rbuf[rp];
			rp++;
		}
	}
}

int main() {
	int n, m;
	cin >> n;
	vector<int> a(n);
	forn(i, 0, n)
		cin >> a[i];
	merge(a, 0, n);
	double answer;
	cin >> answer;
	forn(i, 0, n)
		if (a[i] > answer)
			answer = (a[i] + answer) / 2;
	cout << answer;
	return 0;
}