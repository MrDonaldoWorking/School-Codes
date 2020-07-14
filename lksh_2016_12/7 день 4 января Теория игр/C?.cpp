#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <stdio.h>
#include <queue>

using namespace std;

long long seed, a___, b___, m___;
void init_rand() {
	ifstream in("random.ota");
	in >> seed;
	a___ = 1020;
	b___ = 1203;
	m___ = (long long)1e9 + 7;
}

long long random() {
	ofstream out("random.ota");
	out << (seed = (seed * a___ + b___) % m___);
	return seed;
}

int mex(vector<int> &a) {
	set<int> b(a.begin(), a.end());
	for (int i = 0; ; i++)
		if (!b.count(i))
			return i;
}

void solve() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n;
	in >> n;

	vector<int> ooo(++n);
	vector<int> ooox(n);
	vector<int> xooox(n);
	// obvious situations with n = 1
	xooox[1] = 1;
	// obvious situations with n = 2
	ooox[2] = 0;
	xooox[2] = 0;
	// not obvious situation with n = 1
	ooox[1] = 0;

	for (int i = 3; i < n; ++i) {
		vector<int> curr_ooox;// ooox, xooo
		curr_ooox.push_back(xooox[i - 1]);// xoox
		curr_ooox.push_back(0);// ooxx, xxoo
		for (int pos = 2; pos < i; ++pos)
			curr_ooox.push_back(ooox[pos - 1] ^ xooox[i - pos]);// ooooox -> ooxoox
		ooox[i] = mex(curr_ooox);

		vector<int> curr_xooox;
		curr_xooox.push_back(0);// xxoox, xooxx
		for (int pos = 2; pos < i; ++pos)
			curr_xooox.push_back(xooox[pos - 1] ^ xooox[i - pos]);// xooooox -> xoxooox
		xooox[i] = mex(curr_xooox);

		vector<int> curr_ooo;
		curr_ooo.push_back(ooox[i - 1]);// xoo, oox
		for (int pos = 2; pos < i; ++pos)
			curr_ooo.push_back(ooox[pos - 1] ^ ooox[i - pos]);// ooooo -> oxooo
		ooo[i] = mex(curr_ooo);
	}

	out << (ooo.back() > 0 ? 1 : 2);

	return;
}

void false_solve() {
	ifstream in("input.txt");
	ofstream out("foutput.txt");

	int n;
	in >> n;

	int g[2007];
	g[0] = 0;
	g[1] = 1;
	g[2] = 1;
	for (int i = 3; i <= n; ++i) {
		vector<int> curr_g(1, g[i - 3]);

		for (int pos = 2; pos < i; ++pos)
			curr_g.push_back(g[max(0, pos - 3)] ^ g[max(0, i - pos - 2)]);

		g[i] = mex(curr_g);
	}

	out << (g[n] > 0 ? 1 : 2);

	return;
}

void generator(int oks) {
	ofstream out("input.txt");

	out << oks;

	return;
}

bool validator() {
	ifstream in("output.txt");
	ifstream fin("foutput.txt");

	string s, t;
	while (getline(in, s) && getline(fin, t)) {
		if (s != t)
			return false;
	}

	return true;
}

int main() {
//	solve();
//	false_solve();
//	return 0;

	init_rand();
	//cout << "Initialized random\n";

	for (int oks = 3; oks <= 2000; ++oks) {
		generator(oks);
		//cout << "Generated test\n";
		solve();
		//cout << "Solved Drag\n";
		false_solve();
		//cout << "Solved My\n";

		if (!validator()) {
			cout << "Fail.\n";
			return 0;
		}
	}

	cout << "OK.\n";

	return 0;
}