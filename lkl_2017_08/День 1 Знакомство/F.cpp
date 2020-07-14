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

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);

	vector<int> a(n + 1);
	forn(i, 1, n + 1)
		scanf("%d", &a[i]);

	vector<ll> fact(13, 1);
	forn(i, 2, 13)
		fact[i] = i * fact[i - 1];

	vector<bool> used(n + 1, false);
	ll ans = 0;
	forn(i, 1, n + 1) {
		forn(j, 1, a[i])
			if (!used[j])
				ans += fact[n - i];
		used[a[i]] = true;
	}

	printf("%d", ans + 1);

	return 0;
}