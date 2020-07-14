#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")

#include <iostream>
#include <stdio.h>
//#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

typedef long long ll;
typedef unsigned long long ull;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
#define all(a) a.begin(), a.end()

template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

using namespace std;

static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

struct people {
	int type;
	int ftime;
	int prevtype;
	int num;
};

int main() {
	freopen("hats.in", "r", stdin);
	freopen("hats.out", "w", stdout);

	int n;
	scanf("%d", &n);

	people cutting = { -1, -1, -1, -1 };
	/*scanf("%d%d%d", &cutting.type, &cutting.ftime, &cutting.num);
	cutting.ftime += cutting.num;
	cutting.num = 0;*/

	vector<bool> escape(n, false);
	deque<people> q;
	forn(i, 0, n) {
		int f, s, t;
		scanf("%d%d%d", &f, &s, &t);

		while (!q.empty() && cutting.ftime < s) {
			cutting = q.front();
			q.pop_front();
		}
		if (cutting.ftime < s) {
			//printf("1 %d\n", t + s);
			cutting = { f, t + s, -1, i };
			continue;
		}

		//NEW!
		if (!q.empty())
			q.front().prevtype = -1;

		if (!q.empty() && q.back().type == q.back().prevtype && f != q.back().type) {
			int tt = q.back().type;
			while (!q.empty() && q.back().type == tt) {
				escape[q.back().num] = true;
				q.pop_back();
			}
		}
		if (q.empty()) {
			//printf("2 %d\n", cutting.ftime + t);
			q.push_back({ f, cutting.ftime + t, -1, i });
		}
		else {
			//printf("3 %d\n", q.back().ftime + t);
			q.push_back({ f, q.back().ftime + t, q.back().type, i });
		}
	}

	forn(i, 0, n)
		if (!escape[i])
			printf("%d ", i + 1);

	return 0;
}