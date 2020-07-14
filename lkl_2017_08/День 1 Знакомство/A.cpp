#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")

#include <iostream>
#include <stdio.h>
//#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

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

int binsearch(vector<int> &a, int x) {
	int left = -1, right = a.size() - 1;
	while (right - left > 1) {
		int middle = (left + right) / 2;
		if (a[middle] < x)
			left = middle;
		else
			right = middle;
	}

	return right;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);

	vector<int> a(n);
	forn(i, 0, n)
		scanf("%d", &a[i]);

	int m;
	scanf("%d", &m);

	forn(i, 0, m) {
		int x;
		scanf("%d", &x);

		printf("%d\n", (a[binsearch(a, x)] == x ? binsearch(a, x) + 1 : 0));
	}

	return 0;
}