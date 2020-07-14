#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

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

struct node {
	int prior;
	node *l;
	node *r;
	int subtree_size;
	int val;
	ll sum;
	node(int prior_, int subtree_size_, int val_, int sum_) {
		prior = prior_;
		subtree_size = subtree_size_;
		val = val_;
		sum = sum_;
		l = r = nullptr;
	}
};

node *rootodd = nullptr;
node *rooteven = nullptr;

int getsubtree_size(node *tree) {
	if (tree == nullptr)
		return 0;
	return tree->subtree_size;
}

ll getsum(node *vertex) {
	if (vertex == nullptr)
		return 0;
	return vertex->sum;
}

void update(node *tree) {
	if (tree == nullptr)
		return;

	tree->subtree_size = getsubtree_size(tree->l) + getsubtree_size(tree->r) + 1;
	tree->sum = getsum(tree->l) + getsum(tree->r) + tree->val;
}

pair<node*, node*> split(node *tree, int key) {
	if (tree == nullptr)
		return{ nullptr, nullptr };

	if (getsubtree_size(tree->l) == key) {
		node *tmp = tree->l;
		tree->l = nullptr;
		update(tree);
		return{ tmp, tree };
	}
	if (getsubtree_size(tree->l) > key) {
		auto tmp = split(tree->l, key);
		tree->l = tmp.second;
		update(tree);
		return{ tmp.first, tree };
	}
	else {
		auto tmp = split(tree->r, key - getsubtree_size(tree->l) - 1);
		tree->r = tmp.first;
		update(tree);
		return{ tree, tmp.second };
	}
}

node* merge(node *L, node *R) {
	if (L == nullptr)
		return R;
	if (R == nullptr)
		return L;

	if (L->prior > R->prior) {
		L->r = merge(L->r, R);
		update(L);
		return L;
	}
	else {
		R->l = merge(L, R->l);
		update(R);
		return R;
	}
}

int get(node *tree, int ind) {
	if (tree == nullptr)
		return 55555555;
	int tmp = getsubtree_size(tree->l);
	if (tmp == ind)
		return tree->val;
	if (tmp >= ind)
		return get(tree->l, ind);
	if (tmp <= ind)
		return get(tree->r, ind - (tmp + 1));
}

node* inserteven(node *vertex) {//insert to back
	return merge(rooteven, vertex);
}

node* insertodd(node *vertex) {
	return merge(rootodd, vertex);
}

int main() {
	//freopen("bst1.in", "r", stdin);
	//freopen("bst1.out", "w", stdout);
	ifstream in("swapper.in");
	ofstream out("swapper.out");

	for (int qqq = 1;; qqq++) {
		int n, m;
		in >> n >> m;

		if (n == 0 && m == 0)
			return 0;

		if (qqq > 1)
			out << '\n';

		rooteven = nullptr;
		rootodd = nullptr;
		out << "Swapper " << qqq << ":\n";

		//ios::sync_with_stdio(0);
		//cin.tie(0);

		//root = new node(7, 0); //7 - key, 0 - prior;
		forn(i, 0, n) {
			int x;
			in >> x;

			node *vertex = new node(rand(), 1, x, x);
			if (i % 2 == 0)
				rooteven = inserteven(vertex);
			else
				rootodd = insertodd(vertex);
		}

		forn(i, 0, m) {
			int x, l, r;
			in >> x >> l >> r;
			l--;
			int len = r - l;

			//printf("l - 1 = %d r = %d\n", l, r);

			if (x == 2 && l == r - 1) {
				if (l % 2 == 0) {
					auto tmpeven = split(rooteven, l / 2);
					auto tmppeven = split(tmpeven.second, 1);
					out << tmppeven.first->sum << '\n';
					tmpeven.second = merge(tmppeven.first, tmppeven.second);
					rooteven = merge(tmpeven.first, tmpeven.second);
				}
				else {
					auto tmpodd = split(rootodd, l / 2);
					auto tmppodd = split(tmpodd.second, 1);
					out << tmppodd.first->sum << '\n';
					tmpodd.second = merge(tmppodd.first, tmppodd.second);
					rootodd = merge(tmpodd.first, tmpodd.second);
				}

				continue;
			}

			if (x == 1) {
				auto tmpeven = split(rooteven, (l + 1) / 2);
				auto tmppeven = split(tmpeven.second, (len + (l % 2 == 0 && r % 2 == 1 ? 1 : 0)) / 2);
				auto tmpodd = split(rootodd, l / 2);
				auto tmppodd = split(tmpodd.second, len - (len + (l % 2 == 0 && r % 2 == 1 ? 1 : 0)) / 2);

				//tmpp.first->to_flip = true;
				tmpeven.second = merge(tmppodd.first, tmppeven.second);
				tmpodd.second = merge(tmppeven.first, tmppodd.second);

				//printf("split swapper even: l = %d, len = %d\n", l / 2 + (l % 2 == 0 ? 1 : 0), (r - l) / 2 + (l % 2 == 0 ? 1 : 0));
				//printf("split swapper odd: l = %d, len = %d\n", l / 2, (r - l) / 2);

				rooteven = merge(tmpeven.first, tmpeven.second);
				rootodd = merge(tmpodd.first, tmpodd.second);
			}
			if (x == 2) {
				auto tmpeven = split(rooteven, (l + 1) / 2);
				auto tmppeven = split(tmpeven.second, (len + (l % 2 == 0 && r % 2 == 1 ? 1 : 0)) / 2);
				auto tmpodd = split(rootodd, l / 2);
				auto tmppodd = split(tmpodd.second, len - (len + (l % 2 == 0 && r % 2 == 1 ? 1 : 0)) / 2);

				out << tmppeven.first->sum + tmppodd.first->sum << '\n';

				tmpeven.second = merge(tmppeven.first, tmppeven.second);
				tmpodd.second = merge(tmppodd.first, tmppodd.second);

				//printf("split getsum even: l = %d, len = %d\n", (l + 1) / 2, (len + (l % 2 == 0 && r % 2 == 1 ? 1 : 0)) / 2);
				//printf("split getsum odd: l = %d, len = %d\n", l / 2, len - (len + (l % 2 == 0 && r % 2 == 1 ? 1 : 0)) / 2);

				rooteven = merge(tmpeven.first, tmpeven.second);
				rootodd = merge(tmpodd.first, tmpodd.second);
			}

			/*forn(j, 0, n)
			out << (j % 2 == 0 ? get(rootodd, j / 2) : get(rooteven, j / 2)) << ' ';
			out << '\n';*/
			/*out << "even: ";
			forn(j, 0, n) {
				if (get(rooteven, j) == 55555555)
					break;
				out << get(rooteven, j) << ' ';
			}
			out << "\nodd:  ";
			forn(j, 0, n) {
				if (get(rootodd, j) == 55555555)
					break;
				out << get(rootodd, j) << ' ';
			}
			out << "\n\n";*/
		}
	}

	return 0;
}