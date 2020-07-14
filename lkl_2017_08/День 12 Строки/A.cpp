#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")

#include <iostream>
#include <stdio.h>
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

int main() {
	ifstream in("zfunction.in");
	ofstream out("zfunction.out");

	string s;
	in >> s;

	int n = s.size(), l = 0, r = 0;
	vector<int> z(n, 0);
	forn(i, 1, n) {
		z[i] = max(min(r - i, z[i - l]), 0);

		while (i + z[i] < n && s[z[i]] == s[z[i] + i])
			z[i]++;

		if (i + z[i] >= r) {
			l = i;
			r = z[i] + i;
		}
	}

	for (int i : z)
		out << i << ' ';

	return 0;
}