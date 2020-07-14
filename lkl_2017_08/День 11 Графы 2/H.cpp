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

vector<int> p;

void init(int max_n)  {
	p.resize(max_n);
	forn(i, 0, max_n)
		p[i] = i;
}

int find_set(int x) {
	if (x == p[x])
		return x;
	return p[x] = find_set(p[x]);
}

void unite(int x, int y) {
	x = find_set(x);
	y = find_set(y);
	if (rand() & 1)
		p[y] = x;
	else
		p[x] = y;
}

struct infile {
	bool cut;
	int a;
	int b;
};

int main() {
	freopen("cutting.in", "r", stdin);
	freopen("cutting.out", "w", stdout);

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	vector<vector<int>> graph(n);
	forn(i, 0, m) {
		int from, to;
		scanf("%d%d", &from, &to);
		from--;
		to--;

		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	init(n);

	vector<infile> in(k);
	forn(i, 0, k) {
		char c;
		scanf("%c", &c); //scanf '\n'
		scanf("%c", &c); //scanf first symbol

		if (c == 'a') {
			while (c != ' ')
				scanf("%c", &c);

			int a, b;
			scanf("%d%d", &a, &b);

			in[i] = { false, a, b };
		}
		else {
			while (c != ' ')
				scanf("%c", &c);

			int a, b;
			scanf("%d%d", &a, &b);

			in[i] = { true, a, b };
		}
	}

	vector<bool> ans;
	form(i, k, 0) {
		if (in[i].cut) {
			unite(in[i].a - 1, in[i].b - 1);
		}
		else {
			if (find_set(in[i].a - 1) == find_set(in[i].b - 1))
				ans.push_back(true);
			else
				ans.push_back(false);
		}
	}

	int t = ans.size();
	form(i, t, 0) {
		if (ans[i])
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}