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

struct Vector {
	int x;
	int y;
};

double dist(Vector a, Vector b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

const double EPS = 1e-6;

vector<int> p;

int dsu_get(int v) {
	return (v == p[v]) ? v : (p[v] = dsu_get(p[v]));
}

void dsu_unite(int a, int b) {
	a = dsu_get(a);
	b = dsu_get(b);
	if (rand() & 1)
		swap(a, b);
	if (a != b)
		p[a] = b;
}

struct edge {
	int from;
	int to;
	double w;

	bool operator <(const edge &e) const {
		return w + EPS < e.w;
	}
};

int main() {
	freopen("unionday.in", "r", stdin);
	freopen("unionday.out", "w", stdout);

	int n;
	scanf("%d", &n);

	vector<Vector> polygon(n);
	forn(i, 0, n)
		scanf("%d%d", &polygon[i].x, &polygon[i].y);

	/*for (auto i : polygon) {
		printf("%.9f %.9f\n", i.x, i.y);
	}
	printf("\n");*/

	/*vector<edge> graph;
	forn(i, 0, n) {
		forn(j, i + 1, n) {
			graph.push_back({ i, j, dist(polygon[i], polygon[j]) });
		}
	}*/

	vector<bool> used(n, false);
	vector<double> min_e(n, INF);
	vector<int> sel_e(n, -1);
	min_e[0] = 0;
	double ans = 0;
	forn(i, 0, n) {
		int v = -1;
		forn(j, 0, n) {
			if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
				v = j;
		}

		used[v] = true;

		if (min_e[v] != -1)
			ans += min_e[v];

		forn(to, 0, n) {
			if (dist(polygon[v], polygon[to]) + EPS/*g[v][to]*/ < min_e[to])
				min_e[to] = dist(polygon[v], polygon[to]);
		}
	}

	printf("%.9f", ans);
	//printf("%.9f", cost);
	//for (auto i : res)
		//printf("%d %d\n", i.first, i.second);

	return 0;
}