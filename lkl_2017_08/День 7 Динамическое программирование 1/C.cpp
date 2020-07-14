#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")

#include <iostream>
//#include <stdio.h>
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
const int mod = 1e9 + 7;

ll algo(string &s) {
	if (s == "0")
		return 1;

	int n = s.size();
	vector<vector<ll>> dp(n + 1, vector<ll>(10, 0));
	bool ok = true;

	for (int i = 0; i < n; i++) {
		if (i > 0 && s[i - 1] > s[i])
			ok = false;

		for (int j = 0; j <= 9; j++) {
			for (int dig = j; dig <= 9; dig++) {
				dp[i + 1][dig] += dp[i][j];
				dp[i + 1][dig] %= mod;
			}
		}
		if (ok) {
			for (int dig = (i > 0 ? s[i - 1] - '0' : 0); dig < s[i] - '0'; dig++) {
				dp[i + 1][dig]++;
				dp[i + 1][dig] %= mod;
			}
		}
	}

	ll ans = 0;
	for (int i : dp[n]) {
		ans += i;
		ans %= mod;
	}

	/*forn(i, 0, n + 1) {
		for (int j = 0; j <= 9; j++) {
			printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
		}
		printf("\n");
	}*/

	if (ok)
		ans++;

	return ans % mod;
}

int main() {
	ifstream in("numbers.in");
	ofstream out("numbers.out");

	string L, R;
	in >> L >> R;

	if (L.back() > '0')
		L[L.size() - 1] = L.back() - 1;

	/*out << L << '\n' << R << '\n' << '\n';

	for (int i = 0; i < 151; i++) {
		string g;
		int u = i;
		while (u > 0) {
			g += u % 10 + '0';
			u /= 10;
		}
		reverse(all(g));
		out << i << " = " << algo(g) << '\n';
	}*/
	
	out << ((algo(R) - algo(L)) % mod + mod) % mod;
	
	return 0;
}