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
//�KAN
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
	int key;
	int prior;
	node *l;
	node *r;
	node(int key_, int prior_) {
		key = key_;
		prior = prior_;
		l = r = nullptr;
	}
};

node *root = nullptr;

pair<node*, node*> split(node *tree, int key) {
	if (tree == nullptr)
		return{ nullptr, nullptr };
	if (tree->key < key) {
		pair<node*, node*> tmp = split(tree->r, key);
		tree->r = tmp.first;
		return{ tree, tmp.second };
	}
	else {
		pair<node*, node*> tmp = split(tree->l, key);
		tree->l = tmp.second;
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
		return L;
	}
	else {
		R->l = merge(L, R->l);
		return R;
	}
}

node* insert(node *vertex) {
	pair<node*, node*> one_two;
	one_two = split(root, vertex->key);

	one_two.first = merge(one_two.first, vertex);
	return merge(one_two.first, one_two.second);
}

node* erase(int key) {
	pair<node*, node*> one_two;
	one_two = split(root, key);

	node *three = one_two.first;
	one_two = split(one_two.second, key + 1);//one_two.second - eraseable vertex
	return merge(three, one_two.second);
}

bool search(node *tree, int key) {
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
	ifstream in("bst1.in");
	ofstream out("bst1.out");

	//ios::sync_with_stdio(0);
	//cin.tie(0);

	//root = new node(7, 0); //7 - key, 0 - prior;
	string s;
	while (in >> s) {
		int x;
		in >> x;

		if (s == "insert" && !search(root, x)) {
			node *vertex = new node(x, rand() % 10000 - 5000);
			root = insert(vertex);
		}
		if (s == "delete" && search(root, x)) {
			root = erase(x);
		}
		if (s == "exists") {
			out << (search(root, x) == true ? "true\n" : "false\n");
		}
	}

	return 0;
}
