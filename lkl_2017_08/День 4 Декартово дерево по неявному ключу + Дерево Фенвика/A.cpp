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
	int min_;
	bool to_flip;
	node(int prior_, int subtree_size_, int val_, int min__, bool to_flip_) {
		prior = prior_;
		subtree_size = subtree_size_;
		val = val_;
		min_ = min__;
		to_flip = to_flip_;
		l = r = nullptr;
	}
};

node *root = nullptr;

int getsubtree_size(node *tree) {
	if (tree == nullptr)
		return 0;
	return tree->subtree_size;
}

int getmin(node *vertex) {
	if (vertex == nullptr)
		return INF;
	return vertex->min_;
}

void update(node *tree) {
	if (tree == nullptr)
		return;

	tree->subtree_size = getsubtree_size(tree->l) + getsubtree_size(tree->r) + 1;
	tree->min_ = min(tree->val, min(getmin(tree->l), getmin(tree->r)));
}

bool seeflip(node *tree) {
	if (tree == nullptr)
		return false;
	return tree->to_flip;
}

void push(node *vertex) {
	if (seeflip(vertex)) {
		if (vertex->l != nullptr)
			vertex->l->to_flip = !vertex->l->to_flip;
		if (vertex->r != nullptr)
			vertex->r->to_flip = !vertex->r->to_flip;
		vertex->to_flip = false;

		swap(vertex->l, vertex->r);
	}
}

pair<node*, node*> split(node *tree, int key) {
	if (tree == nullptr)
		return { nullptr, nullptr };

	push(tree);

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
		push(L);
		L->r = merge(L->r, R);
		update(L);
		return L;
	}
	else {
		push(R);
		R->l = merge(L, R->l);
		update(R);
		return R;
	}
}

int get(node *tree, int ind) {
	if (tree == nullptr)
		return 55555555;
	push(tree);
	int tmp = getsubtree_size(tree->l);
	if (tmp == ind)
		return tree->val;
	if (tmp >= ind)
		return get(tree->l, ind);
	if (tmp <= ind)
		return get(tree->r, ind - (tmp + 1));
}

node* insert(node *vertex) {//insert to back
	return merge(root, vertex);
}

int main() {
	//freopen("bst1.in", "r", stdin);
	//freopen("bst1.out", "w", stdout);
	ifstream in("reverse.in");
	ofstream out("reverse.out");

	//ios::sync_with_stdio(0);
	//cin.tie(0);

	//root = new node(7, 0); //7 - key, 0 - prior;
	int n, m;
	in >> n >> m;

	forn(i, 0, n) {
		int x;
		in >> x;

		node *vertex = new node(rand(), 1, x, x, false);
		root = insert(vertex);
	}

	forn(i, 0, m) {
		int x, l, r;
		in >> x >> l >> r;
		l--;

		if (x == 1) {
			auto tmp = split(root, l);
			auto tmpp = split(tmp.second, r - l);
			tmpp.first->to_flip = true;
			tmp.second = merge(tmpp.first, tmpp.second);
			root = merge(tmp.first, tmp.second);

			/*forn(j, 0, n)
			out << get(root, j) << ' ';
			out << '\n';*/
		}
		if (x == 2) {
			auto tmp = split(root, l);
			auto tmpp = split(tmp.second, r - l);
			out << tmpp.first->min_ << '\n';
			tmp.second = merge(tmpp.first, tmpp.second);
			root = merge(tmp.first, tmp.second);
		}
	}

	return 0;
}
