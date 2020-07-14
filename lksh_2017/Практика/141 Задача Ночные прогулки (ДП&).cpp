#define _CRT_SECURE_NO_WARNINGS 
#pragma comment(linker, "/STACK:108777216") 

#include <iostream> 
#include <stdio.h>
#include <vector> 
#include <algorithm> 
#include <set>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, b) for (int i = a; i < b; i++) 
#define form(i, a, b) for (int i = a - 1; i >= b; i--) 
#define all(a) a.begin(), a.end() 

template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

using namespace std;

static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

char google_map[302][302][300];//w, h, n
vector<pair<short, short>> ans;

void write_ans() {
	forn(i, 0, ans.size())
		printf("%d %d\n", ans[i].first, ans[i].second);
	exit(0);
}

void rec(int x, int y, int time_n) {
	if (time_n < 0)
		write_ans();

	if (google_map[x][y][time_n] > 5) {
		//printf("%d %d %d\n", x, y, time_n);

		ans[time_n] = make_pair(x, y);
		rec(x - 1, y, time_n - 1);
		rec(x + 1, y, time_n - 1);
		rec(x, y + 1, time_n - 1);
		rec(x, y - 1, time_n - 1);
		//Any cell is adjacent to itself (but solution would go without it)
		rec(x, y, time_n - 1);
	}
}

int main() {
	freopen("drone.in", "r", stdin);
	freopen("drone.out", "w", stdout);

	int w, h, n;
	scanf("%d%d%d", &w, &h, &n);

	forn(i, 1, w + 1) {
		forn(j, 1, h + 1) {
			forn(k, 1, n)
				google_map[i][j][k] = 5;
		}
	}

	forn(i, 1, w + 1) {
		forn(j, 1, h + 1)
			google_map[i][j][0] = 6;
	}

	forn(x, 0, w)
		forn(i, 0, n) {
		google_map[x][0][i] = 0;
		google_map[x][h + 1][i] = 0;
	}
	forn(y, 0, h)
		forn(i, 0, n) {
		google_map[0][y][i] = 0;
		google_map[w + 1][y][i] = 0;
	}

	forn(i, 0, n) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

		for (int x = x1; x <= x2; x++) {
			for (int y = y1; y <= y2; y++) {
				google_map[x][y][i] = 0;
			}
		}
	}

	//printf("---end of input---\n");

	forn(i, 0, n - 1) {
		for (int x = 1; x <= w; x++) {
			for (int y = 1; y <= h; y++) {
				if (google_map[x][y][i] > 5) {
					google_map[x + 1][y][i + 1]++;
					google_map[x - 1][y][i + 1]++;
					google_map[x][y + 1][i + 1]++;
					google_map[x][y - 1][i + 1]++;
					//Any cell is adjacent to itself (but solution would go without it)
					google_map[x][y - 1][i + 1]++;
				}
			}
		}
	}

	//printf("---end of dynamic---\n");

	ans.resize(n);
	for (int x = 1; x <= w; x++) {
		for (int y = 1; y <= h; y++) {
			if (google_map[x][y][n - 1] > 5)
				rec(x, y, n - 1);
		}
	}

	printf("Impossible");

	return 0;
}