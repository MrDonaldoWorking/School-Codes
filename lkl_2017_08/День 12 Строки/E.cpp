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

int sum_prefix_function(string &s) {
	int n = (int)s.length();
	vector<int> pi(n);

	forn(i, 1, n) {
		int j = pi[i - 1];

		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];

		if (s[i] == s[j])
			++j;
		pi[i] = j;
	}

	int sum = 0;
	for (int i : pi)
		sum += i;

	return sum;
}

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n;
	in >> n;
	forn(i, 0, n) {
		string s;
		in >> s;

		string t = "a#" + s;
		int max_sum = 0;
		char ans_sym = 'a';
		for (char c = 'a'; c <= 'z'; c++) {
			t[0] = c;
			int curr_pi = sum_prefix_function(t);

			if (curr_pi > max_sum) {
				max_sum = curr_pi;
				ans_sym = c;
			}
		}

		out << ans_sym << '\n';
	}

	return 0;
}