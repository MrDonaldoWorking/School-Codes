#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")

#include <iostream>
#include <stdio.h>
//#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>

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

struct elem {
	int val;
	int min_;
};

int main() {
	freopen("stack.in", "r", stdin);
	freopen("stack.out", "w", stdout);

	int n;
	scanf("%d", &n);

	stack<elem> a;
	forn(i, 0, n) {
		int x;
		scanf("%d", &x);

		if (x == 1) {
			int y;
			scanf("%d", &y);

			if (!a.empty())
				a.push({ y, min(y, a.top().min_) });
			else
				a.push({ y, y });
		}
		if (x == 2) {
			a.pop();
		}
		if (x == 3) {
			printf("%d\n", a.top().min_);
		}
	}

	return 0;
}