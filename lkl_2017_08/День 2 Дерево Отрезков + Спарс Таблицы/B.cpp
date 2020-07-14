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
	ll sum;
	ll lazy;
	bool flag;
};

vector<tree_node> tree;

ll true_sum(int i, int L, int R) {
	if (tree[i].flag)
		return (R - L) * tree[i].lazy;
	return tree[i].sum;
}

void push(int i, int L, int R) {
	if (tree[i].flag) {
		tree[2 * i + 1].lazy = tree[i].lazy;
		tree[2 * i + 2].lazy = tree[i].lazy;
		tree[2 * i + 1].flag = true;
		tree[2 * i + 2].flag = true;
	}
	//tree[2 * i + 1].flag = true;
	//tree[2 * i + 2].flag = true;

	int M = L + (R - L) / 2;
	tree[i].sum = /*tree[i].lazy * (R - L);*/ true_sum(2 * i + 1, L, M) + true_sum(2 * i + 2, M, R);
	tree[i].lazy = 0;
	tree[i].flag = false;
}

ll getsum(int i, int L, int R, int l, int r) {
	if (L >= l && R <= r) {
		/*printf("%d ", true_sum(i, L, R));
		if (R < r)
			printf("+ ");
		else
			printf("= ");*/
		return true_sum(i, L, R);
	}
	if (L >= r || R <= l)
		return 0;

	push(i, L, R);
	int M = L + (R - L) / 2;
	return getsum(2 * i + 1, L, M, l, r) + getsum(2 * i + 2, M, R, l, r);
}

void add(int i, int L, int R, int l, int r, int delta) {
	if (L >= r || R <= l)
		return;
	if (L >= l && R <= r) {
		tree[i].lazy = delta;
		tree[i].flag = true;
	}
	else {
		push(i, L, R);
		int M = L + (R - L) / 2;
		add(2 * i + 1, L, M, l, r, delta);
		add(2 * i + 2, M, R, l, r, delta);
		tree[i].sum = true_sum(2 * i + 1, L, M) + true_sum(2 * i + 2, M, R);
	}
}

int main() {
	freopen("sum2.in", "r", stdin);
	freopen("sum2.out", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);

	tree.resize(4 * n, { 0, 0, 0 });

	forn(i, 0, m) {
		char c;
		scanf("%c", &c);//We don't need symbol "\n"
		scanf("%c", &c);

		if (c == 'Q') {
			int left, right;
			scanf("%d%d", &left, &right);
			left--;

			printf("%lld\n", getsum(0, 0, n, left, right));
		}
		if (c == 'A') {
			int left, right, delta;
			scanf("%d%d%d", &left, &right, &delta);
			left--;

			add(0, 0, n, left, right, delta);
			/*for (auto i : tree)
				printf("%lld ", i.sum);
			printf("\n");*/
		}
	}

	return 0;
}