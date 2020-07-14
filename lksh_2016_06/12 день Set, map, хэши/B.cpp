#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <queue>
#include <fstream>
#include <set>
#include <string>
#include <map>
typedef long long ll;
typedef unsigned long long ull;
#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
#define pb push_back
#define po pop_back
#define fi first
#define se second
using namespace std;

struct answer {
	int t;
	string s;

	bool operator < (const answer &a) {
		if (t == a.t)
			return s < a.s;
		return t > a.t;
	}
};

int main() {
	map<string, int> s;
	string x;

	while (cin >> x) {
		//s.insert(x);
		s[x]++;
	}

	vector<answer> a(s.size());
	int k = 0;

	for (auto i : s) {
		a[k].t = i.se;
		a[k].s = i.fi;
		k++;
	}

	sort(a.begin(), a.end());

	forn(i, 0, a.size())
		cout << a[i].s << endl;

	return 0;
}