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

	if (n == 1) {
		printf("1\n1");
		return 0;
	}

	vector<int> a(n);
	forn(i, 0, n)
		scanf("%d", &a[i]);
	reverse(all(a));

	if (n == 2) {
		if (a[0] >= a[1])
			printf("2\n1 2");
		else
			printf("1\n1");
		return 0;
	}

	vector<ll> dp(n + 1, INFL);
	vector<int> ind(n + 1, -1);
	vector<int> prev(n);
	dp[0] = -INFL;
	forn(i, 0, n) {
		int j = upper_bound(all(dp), a[i]) - dp.begin();
		dp[j] = a[i];
		ind[j] = i;
		prev[i] = ind[j - 1];

		/*printf("dp:\n");
		forn(j, 0, n + 1) {
			if (dp[j] == -INFL) {
				printf("-INF ");
				continue;
			}
			if (dp[j] == INFL) {
				printf("INF ");
				continue;
			}
			printf("%lld ", dp[j]);
		}
		printf("\n");
		printf("ind:\n");
		forn(j, 0, n + 1)
			printf("%d ", ind[j]);
		printf("\n");
		printf("prev:\n");
		forn(j, 0, n)
			printf("%d ", prev[j]);
		printf("\n\n\n");*/
	}

	int j = n;
	while (dp[j] == INFL)
		j--;

	j = ind[j];
	vector<int> ans;
	while (j > -1) {
		ans.push_back(j);
		j = prev[j];
		//j--;
	}

	int q = ans.size();
	printf("%d\n", q);
	for (int i : ans)
		printf("%d ", n - i);

	return 0;
}

/*
600 200
-600 -200
1200 400
0 0

-600 -200
600 200
1200 400
0 0

-600 -200
600 200
0 0
1200 400

-600 -200
0 0
600 200
1200 400

-200 400
600 -200
-400 -400
600 0
*/