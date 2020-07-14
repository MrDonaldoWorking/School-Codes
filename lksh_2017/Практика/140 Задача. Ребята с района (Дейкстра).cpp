#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")

#include <iostream>
#include <stdio.h>
//#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

typedef long long ll;
typedef unsigned long long ull;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
#define all(a) a.begin(), a.end()

template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

using namespace std;

static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

struct google_map {
	int to;
	int w;
};

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	int n, m, start, finish;
	scanf("%d%d%d%d", &n, &m, &start, &finish);

	vector<vector<google_map>> graph(n);
	forn(i, 0, m) {
		int from, to, w;
		scanf("%d%d%d", &from, &to, &w);

		graph[from - 1].push_back({ to - 1, w });
		graph[to - 1].push_back({ from - 1, w });
	}

	int a, b;
	scanf("%d%d", &a, &b);

	vector<ll> length(n, INFL);
	set<pair<ll, int>> houses;
	length[start - 1] = 0;
	houses.insert({ 0, start - 1 });
	while (!houses.empty()) {
		int curr_v = houses.begin()->second;
		//printf("%d %d\n", houses.begin()->first, curr_v);
		houses.erase(houses.begin());
		for (google_map e : graph[curr_v]) {
			if (length[e.to] > length[curr_v] + e.w && e.w <= a) {
				houses.erase({ length[e.to], e.to });
				length[e.to] = length[curr_v] + e.w;
				houses.insert({ length[e.to], e.to });
			}
		}
	}
	ll ans1 = length[finish - 1];

	forn(i, 0, n) {
		if (length[i] != INFL)
			houses.insert({ length[i], i });
	}
	while (!houses.empty()) {
		int curr_v = houses.begin()->second;
		//printf("%d %d\n", houses.begin()->first, curr_v);
		houses.erase(houses.begin());
		for (google_map e : graph[curr_v]) {
			if (length[e.to] > length[curr_v] + e.w && e.w >= b) {
				houses.erase({ length[e.to], e.to });
				length[e.to] = length[curr_v] + e.w;
				houses.insert({ length[e.to], e.to });
			}
		}
	}
	ll ans2 = length[finish - 1];

	if (ans1 == INFL && ans2 == INFL) {
		printf("-1");
		return 0;
	}

	printf("%lld", min(ans1, ans2));

	return 0;
}