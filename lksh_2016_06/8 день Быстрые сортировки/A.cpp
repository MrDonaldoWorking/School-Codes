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

int k;

void fill(vector<int> & a, int n, int start) {
	a.resize(n);
	a[0] = start;
	for (int i = 1; i < n; ++i)
		a[i] = (1103515245LL * a[i - 1] + 12345) & ((1LL << 31) - 1);
}

void quick(vector<int> &sample, int left, int right) {
	if (right - left <= 1)
		return;
	int x = sample[rand() % (right - left) + left];
	int lt = left, eq = left;
	forn(i, left, right) {
		if (sample[i] == x) {
			//cout << i << ' ' << eq << endl;
			swap(sample[i], sample[eq]);
			eq++;
		}
		if (sample[i] < x) {
			swap(sample[i], sample[eq]);
			swap(sample[eq], sample[lt]);
			eq++;
			lt++;
		}
	}
	if (k == x)
		return;
	if (k >= left && lt > k)
		quick(sample, left, lt);
	else
		quick(sample, eq, right);
}

int main() {
	int n, m;
	cin >> n >> m >> k;
	vector<int> a;
	fill(a, n, m);
	quick(a, 0, n);
	cout << a[k] << endl;
	//forn(i, 0, n)
	//	cout << a[i] << ' ';
	return 0;
}