#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")

#include <iostream>
#include <stdio.h>
//#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

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
const double PI = 3.1415926535897932384626433832795;
const double EPS = 1e-5;

struct tree_node {
	int val;
	int sum;
};

void build(vector<tree_node> &tree, vector<int> &a, int i, int L, int R) {
	if (L + 1 == R) {
		tree[i].val = a[L];
		tree[i].sum = a[L];
	}
	else {
		int M = L + (R - L) / 2;
		build(tree, a, 2 * i + 1, L, M);
		build(tree, a, 2 * i + 2, M, R);

		tree[i].sum = tree[2 * i + 1].sum + tree[2 * i + 2].sum;
	}
}

int getsum(vector<tree_node> &tree, int i, int L, int R, int l, int r) {
	if (L >= l && R <= r)
		return tree[i].sum;
	if (L >= r || R <= l)
		return 0;

	int M = L + (R - L) / 2;
	return getsum(tree, 2 * i + 1, L, M, l, r) + getsum(tree, 2 * i + 2, M, R, l, r);
}

void add(vector<tree_node> &tree, int i, int L, int R, int ind, int delta) {
	if (L > ind || R < ind)
		return;
	if (L + 1 == R) {
		if (L != ind)
			return;

		tree[i].val = delta;
		tree[i].sum = delta;
		return;
	}

	int M = L + (R - L) / 2;
	add(tree, 2 * i + 1, L, M, ind, delta);
	add(tree, 2 * i + 2, M, R, ind, delta);

	tree[i].sum = tree[2 * i + 1].sum + tree[2 * i + 2].sum;
}

int main() {
	freopen("inverse2.in", "r", stdin);
	freopen("inverse2.out", "w", stdout);

	int n;
	scanf("%d", &n);

	vector<tree_node> treei(4 * n);
	vector<tree_node> treek(4 * n);
	vector<int> mi(n, 0);
	vector<int> mk(n, 0);
	vector<int> a(n);
	forn(i, 0, n) {
		scanf("%d", &a[i]);
		a[i]--;
	}

	build(treei, mi, 0, 0, n);
	build(treek, mk, 0, 0, n);

	vector<ll> suffix(n);
	forn(j, 0, n) {
		mi[a[j]] = 1;
		add(treei, 0, 0, n, a[j], 1);

		suffix[j] = getsum(treei, 0, 0, n, a[j] + 1, n);
		//printf("sum[%d, %d) = %d\n", a[j] + 1, n, suffix[j]);
	}

	vector<ll> prefix(n);
	form(j, n, 0) {
		mk[a[j]] = 1;
		add(treek, 0, 0, n, a[j], 1);

		prefix[j] = getsum(treek, 0, 0, n, 0, a[j]);
		//printf("sum[%d, %d) = %d\n", 0, a[j], prefix[j]);
	}

	ll ans = 0;
	forn(i, 0, n)
		ans += prefix[i] * suffix[i];

	printf("%lld", ans);

	return 0;
}