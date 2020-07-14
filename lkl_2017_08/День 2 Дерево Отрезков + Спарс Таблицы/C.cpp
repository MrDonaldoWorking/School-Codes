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

vector<int> a;
vector<vector<int>> st;
vector<int> logs;
ll n;

const int MAX = 1e9 + 7;

void build() {
	st[0] = a;

	int j = 1;
	while ((1 << j) < n) {
		for (int i = 0; i + (1 << j) <= n; i++)
			st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
		j++;
	}
}

int get_min(int l, int r) {
	return min(st[logs[r - l]][l], st[logs[r - l]][r - (1 << logs[r - l]) + 1]);
}

int main() {
	freopen("sparse.in", "r", stdin);
	freopen("sparse.out", "w", stdout);

	ll m, l, d;
	scanf("%lld%lld%lld%lld", &n, &m, &l, &d);

	a.resize(n);
	forn(i, 0, n)
		scanf("%d", &a[i]);

	logs.resize(n, 0);
	forn(i, 2, n)
		logs[i] = logs[i / 2] + 1;

	st.resize(logs.back() + 1, vector<int>(n));

	build();

	/*forn(i, 0, st.size()) {
	forn(j, 0, n)
	printf("%d ", st[i][j]);
	printf("\n");
	}*/

	ll sum = 0;
	forn(i, 0, m) {
		//print ans
		int ans = get_min(l, l + d - 1);
		sum = (sum + ans) % MAX;

		//printf("get_min(%d, %d) = %d\n", l, l + d - 1, ans);

		d = (d + ans * (ll)7 + 11) % n + 1;
		l = (l + ans * (ll)11 + 13) % (n - d + 1);

		//printf("%d\n", get_min(left, right));
	}

	printf("%lld", sum);

	return 0;
}