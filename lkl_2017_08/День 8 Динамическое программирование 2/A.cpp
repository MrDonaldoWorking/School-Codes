#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")

#include <iostream>
#include <stdio.h>
//#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

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
const double PI = 3.1415926535897932384626433832795;
const double EPS = 1e-5;

int main() {
	freopen("backpack.in", "r", stdin);
	freopen("backpack.out", "w", stdout);

	int s, n;
	scanf("%d%d", &s, &n);

	vector<int> Au(n);
	forn(i, 0, n)
		scanf("%d", &Au[i]);

	vector<vector<bool>> backpack(n + 1, vector<bool>(s + 1, false));
	backpack[0][0] = true;
	forn(i, 0, n) {
		forn(j, 0, s + 1) {
			if (backpack[i][j]) {
				backpack[i + 1][j] = true;
				if (Au[i] + j <= s)
					backpack[i + 1][Au[i] + j] = true;
			}
		}
	}

	while (backpack[n][s] == false)
		s--;

	printf("%d", s);

	return 0;
}