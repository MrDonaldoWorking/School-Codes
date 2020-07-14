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
	int max_;
};

vector<tree_node> tree;
vector<int> a;
const int N = 1e5;

void build(int i, int L, int R) {
	if (L + 1 == R) {
		tree[i].min_ = a[L];
		tree[i].max_ = a[L];
	}
	else {
		int M = L + (R - L) / 2;
		build(2 * i + 1, L, M);
		build(2 * i + 2, M, R);

		tree[i].min_ = min(tree[2 * i + 1].min_, tree[2 * i + 2].min_);
		tree[i].max_ = max(tree[2 * i + 1].max_, tree[2 * i + 2].max_);
	}
}

int getmin(int i, int L, int R, int l, int r) {
	if (L >= l && R <= r)
		return tree[i].min_;
	if (L >= r || R <= l)
		return INF;

	int M = L + (R - L) / 2;
	return min(getmin(2 * i + 1, L, M, l, r), getmin(2 * i + 2, M, R, l, r));
}

int getmax(int i, int L, int R, int l, int r) {
	if (L >= l && R <= r)
		return tree[i].max_;
	if (L >= r || R <= l)
		return -INF;

	int M = L + (R - L) / 2;
	return max(getmax(2 * i + 1, L, M, l, r), getmax(2 * i + 2, M, R, l, r));
}

void add(int i, int L, int R, int ind, int delta) {
	if (L > ind || R < ind)
		return;
	if (L + 1 == R) {
		if (L != ind)
			return;

		tree[i].min_ = delta;
		tree[i].max_ = delta;
		return;
	}

	int M = L + (R - L) / 2;
	add(2 * i + 1, L, M, ind, delta);
	add(2 * i + 2, M, R, ind, delta);

	tree[i].min_ = min(tree[2 * i + 1].min_, tree[2 * i + 2].min_);
	tree[i].max_ = max(tree[2 * i + 1].max_, tree[2 * i + 2].max_);
}

int main() {
	freopen("rvq.in", "r", stdin);
	freopen("rvq.out", "w", stdout);

	a.resize(N);
	for (ll i = 1; i <= N; i++) {
		a[i - 1] = i * i % 12345 + i * i * i % 23456;
		//printf("%d ", a[i - 1]);
	}
	//printf("\n");

	tree.resize(4 * N);

	build(0, 0, N);

	int m;
	scanf("%d", &m);

	forn(i, 0, m) {
		int x, y;
		scanf("%d%d", &x, &y);

		if (x < 0)
			add(0, 0, N, -x - 1, y);
		if (x > 0)
			//printf("%d - %d = %d\n", getmax(0, 0, N, x - 1, y), getmin(0, 0, N, x - 1, y), getmax(0, 0, N, x - 1, y) - getmin(0, 0, N, x - 1, y));
			printf("%d\n", getmax(0, 0, N, x - 1, y) - getmin(0, 0, N, x - 1, y));
	}

	return 0;
}