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

struct trie {
	char c;
	vector<trie*> child;
	bool flag;
	int num;

	trie() {
		c = 0;
		num = -1;
		flag = false;
		child.resize(26, nullptr);
	}

	trie(char c_, bool flag_, int num_) {
		c = c_;
		flag = flag_;
		num = num_;
	}
};

trie *root = nullptr;

trie* insert(trie *tree, string &s, int i, int num) {
	if (s.size() - 1 == i)
		return tree;

	if (tree == nullptr) {
		tree = new trie();
		tree->c = s[i];
		tree->flag = (i == s.size() - 2 ? true : false);
		tree->num = num;
	}

	tree->child[s[i + 1] - 'a'] = insert(tree->child[s[i + 1] - 'a'], s, i + 1, num);

	return tree;
}

void search(trie *tree, string &s, int pos, int left, int right, vector<bool> &ans) {
	if (tree == nullptr)
		return;
	if (pos == right)
		return;

	if (tree->flag) {
		ans[tree->num] = true;
	}

	if (pos + 1 == right)
		return;

	search(tree->child[s[pos + 1] - 'a'], s, pos + 1, left, right, ans);
}

int main() {
	ifstream in("dictionary.in");
	ofstream out("dictionary.out");

	string t;
	in >> t;

	int m = t.size();

	root = new trie();
	root->c = '#';
	root->flag = false;
	root->num = -1;

	int n;
	in >> n;
	forn(i, 0, n) {
		string s;
		in >> s;
		s += 'z';

		//out << root->child[s[0] - 'a'] << ' ' << s[0] - 'a' << '\n';
		root->child[s[0] - 'a'] = insert(root->child[s[0] - 'a'], s, 0, i);
	}

	vector<bool> ans(n, false);
	forn(i, 0, m) {
		search(root->child[t[i] - 'a'], t, i, i, min(i + 30, m - 1) + 1, ans);
	}

	forn(i, 0, n) {
		if (ans[i])
			out << "Yes\n";
		else
			out << "No\n";
	}

	return 0;
}