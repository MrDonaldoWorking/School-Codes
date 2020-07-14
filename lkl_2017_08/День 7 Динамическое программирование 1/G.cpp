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
const double PI = 3.1415926535897932384626433832795;

int main() {
	ifstream in("palindr.in");
	ofstream out("palindr.out");

	string s;
	in >> s;

	int n = s.size();
	vector<vector<int>> dp(n, vector<int>(n, 0));
	forn(i, 0, n)
		dp[i][i] = 1;
	forn(i, 0, n - 1) {
		if (s[i] == s[i + 1])
			dp[i][i + 1] = 2;
	}

	forn(len, 2, n + 1) {
		forn(l, 0, n - len + 1) {
			int r = l + len - 1;
			amax(dp[l][r], max(dp[l + 1][r], dp[l][r - 1]));
			if (s[l] == s[r])
				amax(dp[l][r], dp[l + 1][r - 1] + 2);
		}
	}

	/*forn(i, 0, n) {
		forn(j, 0, n)
			out << dp[i][j] << ' ';
		out << '\n';
	}*/

	string ans;
	int l = 0, r = n - 1;
	while (r - l > 0) {
		if (l == r) {//ans + s[l] + sna
			break;
		}//ans + sna

		if (s[l] == s[r]) {
			ans += s[l];
			l++;
			r--;
			continue;
		}
		if (dp[l][r - 1] > dp[l + 1][r])
			r--;
		else
			l++;
	}

	string revans = ans;
	reverse(all(revans));

	if (dp[0][n - 1] % 2 == 1)
		out << ans + s[l] + revans;
	else
		out << ans + revans;

	return 0;
}