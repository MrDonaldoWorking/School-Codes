#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")

#include <iostream>
#include <stdio.h>
//#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>

using ll = long long;
using ull = unsigned long long;
using ld = long double;
//©KAN
//template<typename T>
//using pair2<T> = pair<T, T>;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
#define all(a) a.begin(), a.end()

template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

using namespace std;

static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

int n;

int f(int i) {
	return i & (i + 1);
}

int f2(int i) {
	return i | (i + 1);
}

void add(vector<vector<vector<ll>>> &tree, int indx, int indy, int indz, int delta) {
	for (int i = indx; i < n; i = f2(i))
		for (int j = indy; j < n; j = f2(j))
			for (int k = indz; k < n; k = f2(k))
				tree[i][j][k] += delta;
}

int sum(vector<vector<vector<ll>>> &tree, int indx, int indy, int indz) {
	if (indx < 0 || indy < 0 || indz < 0)
		return 0;

	ll ans = 0;
	for (int i = indx; i >= 0; i = f(i) - 1)
		for (int j = indy; j >= 0; j = f(j) - 1)
			for (int k = indz; k >= 0; k = f(k) - 1)
				ans += tree[i][j][k];
	return ans;
}

int main() {
	freopen("stars.in", "r", stdin);
	freopen("stars.out", "w", stdout);

	scanf("%d", &n);

	vector<vector<vector<ll>>> fenwick(n, vector<vector<ll>>(n, vector<ll>(n, 0)));

	int m = 0;
	while (m != 3) {
		scanf("%d", &m);
		if (m == 1) {
			int x, y, z, k;
			scanf("%d%d%d%d", &x, &y, &z, &k);

			add(fenwick, x, y, z, k);
		}
		if (m == 2) {
			int x1, y1, z1, x2, y2, z2;
			scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);

			cout << sum(fenwick, x2, y2, z2) - sum(fenwick, x1 - 1, y2, z2) - sum(fenwick, x2, y1 - 1, z2) + sum(fenwick, x1 - 1, y1 - 1, z2) - sum(fenwick, x2, y2, z1 - 1) + sum(fenwick, x1 - 1, y2, z1 - 1) + sum(fenwick, x2, y1 - 1, z1 - 1) - sum(fenwick, x1 - 1, y1 - 1, z1 - 1) << '\n';
		}
	}

	return 0;
}