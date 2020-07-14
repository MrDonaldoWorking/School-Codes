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

const int P = 239;
const ull M1 = 1e9 + 9, M2 = 1e9 + 7;

ull ha(ull left, ull right, ull div, vector<ull> &h, vector<ull> &p) {
	return (h[right] - (h[left] * p[right - left]) % div + (2 * div)) % div;
}

int main() {
	ifstream in("cubes.in");
	ofstream out("cubes.out");

	int n, m;
	in >> n >> m;

	vector<int> cubes(n);
	forn(i, 0, n)
		in >> cubes[i];

	vector<int> sebuc(n);
	forn(i, 0, n)
		sebuc[n - i - 1] = cubes[i];

	vector<ull> power1(n + 1);
	vector<ull> power2(n + 1);
	power1[0] = 1;
	power2[0] = 1;
	forn(i, 1, n + 1) {
		power1[i] = (power1[i - 1] * P) % M1;
		power2[i] = (power2[i - 1] * P) % M2;
	}
	vector<ull> hash1(n + 1, 0);
	vector<ull> hash2(n + 1, 0);
	forn(i, 1, n + 1) {
		hash1[i] = (hash1[i - 1] * P) % M1;
		hash1[i] = (hash1[i] + cubes[i - 1]) % M1;
		hash2[i] = (hash2[i - 1] * P) % M1;
		hash2[i] = (hash2[i] + sebuc[i - 1]) % M1;
		//cout << hash1[i] << ' ' << hash2[i] << endl;
		//cout << ha(i - 1, i, M1, hash1, power1) << ' ';
		//cout << ha(i - 1, i, M1, hash1, power1) << endl;  
	}
	//cout << endl;

	form(i, n / 2 + 1, 1) {
		if (ha(0, i, M1, hash1, power1) == ha(n - 2 * i, n - i, M1, hash2, power1))
			out << n - i << ' ';
		//out << 0 << ' ' << i << ' ' << n - 2 * i << ' ' << n - i << '\n';
	}

	out << n;

	return 0;
}