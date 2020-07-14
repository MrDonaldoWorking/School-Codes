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
const int MAX_N = 1e9;

struct node {
	ll key;
	int prior;
	node *l;
	node *r;
	int subtree_size;
	ll sum;
	node(ll key_, int prior_, int subtree_size_, ll sum_) {
		key = key_;
		prior = prior_;
		subtree_size = subtree_size_;
		sum = sum_;
		l = r = nullptr;
	}
};

node *root = nullptr;

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
	tree->sum = getsum(tree->l) + getsum(tree->r) + tree->key;
}

pair<node*, node*> split(node *tree, ll key) {
	if (tree == nullptr)
		return{ nullptr, nullptr };
	if (tree->key < key) {
		pair<node*, node*> tmp = split(tree->r, key);
		tree->r = tmp.first;
		update(tmp.second);
		update(tree);
		return{ tree, tmp.second };
	}
	else {
		pair<node*, node*> tmp = split(tree->l, key);
		tree->l = tmp.second;
		update(tmp.first);
		update(tree);
		return{ tmp.first, tree };
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

/*int get(node *tree, int ind) {
	if (tree == nullptr)
		return 55555555;
	int tmp = getsubtree_size(tree->l);
	if (tmp == ind)
		return tree->key;
	if (tmp >= ind)
		return get(tree->l, ind);
	if (tmp <= ind)
		return get(tree->r, ind - (tmp + 1));
}*/

node* insert(node *vertex) {
	pair<node*, node*> one_two;
	one_two = split(root, vertex->key);

	one_two.first = merge(one_two.first, vertex);
	return merge(one_two.first, one_two.second);
}

bool search(node *tree, ll key) {
	if (tree == nullptr)
		return false;
	if (tree->key == key)
		return true;

	if (tree->key > key)
		return search(tree->l, key);
	return search(tree->r, key);
}

int main() {
	//freopen("bst1.in", "r", stdin);
	//freopen("bst1.out", "w", stdout);
	ifstream in("sum.in");
	ofstream out("sum.out");

	//ios::sync_with_stdio(0);
	//cin.tie(0);

	//root = new node(7, 0); //7 - key, 0 - prior;
	int m;
	in >> m;

	srand(114514);

	ll ans = 0;
	int n = 0;
	char prevc = 'h';
	forn(i, 0, m) {
		char c;
		in >> c;

		if (c == '+') {
			ll x;
			in >> x;

			if (prevc == '?') {
				if (!search(root, (x + ans) % MAX_N)) {
					node *vertex = new node((x + ans) % MAX_N, rand(), 1, (x + ans) % MAX_N);
					root = insert(vertex);
					n++;
				}
			}
			else {
				if (!search(root, x)) {
					node *vertex = new node(x, rand(), 1, x);
					root = insert(vertex);
					n++;
				}
			}

			/*forn(i, 0, n)
				out << get(root, i) << ' ';
			out << '\n';*/
		}
		if (c == '?') {
			int l, r;
			in >> l >> r;

			auto tmp = split(root, l);
			auto tmpp = split(tmp.second, r + 1);

			out << (tmpp.first == nullptr ? 0 : tmpp.first->sum) << '\n';
			ans = (tmpp.first == nullptr ? 0 : tmpp.first->sum);

			tmp.second = merge(tmpp.first, tmpp.second);
			root = merge(tmp.first, tmp.second);
		}

		prevc = c;
	}

	return 0;
}