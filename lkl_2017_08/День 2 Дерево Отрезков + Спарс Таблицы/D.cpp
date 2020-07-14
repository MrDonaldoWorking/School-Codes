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

struct tree_node {
	int min_;
	int val;
};

vector<tree_node> tree;
vector<int> a;
const int MAX_N = 1e6 + 7;

void build(int i, int L, int R) {
	if (L + 1 == R) {
		tree[i].min_ = a[L];
		tree[i].val = a[L];
	}
	else {
		int M = L + (R - L) / 2;
		build(2 * i + 1, L, M);
		build(2 * i + 2, M, R);

		tree[i].min_ = min(tree[2 * i + 1].min_, tree[2 * i + 2].min_);
	}
}

int getmin(int i, int L, int R, int l, int r) {
	if (L >= l && R <= r) {
		//printf("used tree[%d].min_ = %d\n", i, tree[i].min_);
		return tree[i].min_;
	}
	if (L >= r || R <= l)
		return INF;

	int M = L + (R - L) / 2;
	return min(getmin(2 * i + 1, L, M, l, r), getmin(2 * i + 2, M, R, l, r));
}

void add(int i, int L, int R, int ind) {
	if (L > ind || R < ind)
		return;
	if (L + 1 == R) {
		if (L != ind)
			return;

		tree[i].val = INF;
		tree[i].min_ = INF;
		//printf("tree[%d] changed to %d\n", i, INF);
		return;
	}

	int M = L + (R - L) / 2;
	add(2 * i + 1, L, M, ind);
	add(2 * i + 2, M, R, ind);

	tree[i].min_ = min(tree[2 * i + 1].min_, tree[2 * i + 2].min_);
}

void erase(int i, int L, int R, int ind) {
	if (L > ind || R < ind)
		return;
	if (L + 1 == R) {
		if (L != ind)
			return;

		tree[i].val = ind;
		tree[i].min_ = ind;
		//printf("tree[%d] changed to %d\n", i, ind);
		return;
	}

	int M = L + (R - L) / 2;
	erase(2 * i + 1, L, M, ind);
	erase(2 * i + 2, M, R, ind);

	tree[i].min_ = min(tree[2 * i + 1].min_, tree[2 * i + 2].min_);
}

int main() {
	freopen("floor4.in", "r", stdin);
	freopen("floor4.out", "w", stdout);

	a.resize(MAX_N);
	forn(i, 0, MAX_N)
		a[i] = i;

	tree.resize(MAX_N * 4);
	build(0, 0, MAX_N);

	int m;
	scanf("%d", &m);
	forn(i, 0, m) {
		int x;
		scanf("%d", &x);

		if (x > 0) {
			int ans = getmin(0, 0, MAX_N, x - 1, MAX_N);
			printf("%d\n", ans + 1);
			add(0, 0, MAX_N, ans);
		}
		else
			erase(0, 0, MAX_N, -x - 1);
	}

	return 0;
}