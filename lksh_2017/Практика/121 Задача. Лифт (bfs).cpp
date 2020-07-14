#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")

#include <iostream>
#include <stdio.h>
//#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

typedef long long ll;
typedef unsigned long long ull;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
#define all(a) a.begin(), a.end()

template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

using namespace std;

static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

vector<int> lbuf, rbuf;
vector<int> a;
int ans = 0;

void Merge(int left, int right) {
	if (right - left <= 1)
		return;
	int mid = (left + right) / 2;
	Merge(left, mid);
	Merge(mid, right);
	lbuf.assign(a.begin() + left, a.begin() + mid);
	lbuf.push_back(INF);
	rbuf.assign(a.begin() + mid, a.begin() + right);
	rbuf.push_back(INF);
	int lp = 0, rp = 0;
	forn(i, left, right) {
		if (lbuf[lp] <= rbuf[rp]) {
			a[i] = lbuf[lp];
			lp++;
		}
		else {
			a[i] = rbuf[rp];
			rp++;
		}
	}
}

int main() {
	freopen("elevator.in", "r", stdin);
	freopen("elevator.out", "w", stdout);

	int n, s;
	scanf("%d%d", &n, &s);
	s--;

	vector<vector<int>> graph(n);
	forn(i, 0, n) {
		int k;
		scanf("%d", &k);
		forn(j, 0, k) {
			int t;
			scanf("%d", &t);
			graph[i].push_back(t - 1);
		}
	}

	vector<int> length(n, -1);
	length[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		for (int i : graph[q.front()])
			if (length[i] == -1) {
				length[i] = length[q.front()] + 1;
				q.push(i);
			}
		q.pop();
	}

	int max_ = -1;
	forn(i, 0, n)
		max_ = max(max_, length[i]);

	printf("%d\n", max_);
	forn(i, 0, n)
		if (length[i] == max_)
			printf("%d ", i + 1);

	return 0;
}