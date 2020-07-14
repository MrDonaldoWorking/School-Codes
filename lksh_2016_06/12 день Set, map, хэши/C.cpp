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
int main() {
	map<string, vector<string>> rev_m;
	string s;
	while (cin >> s) {
		char c;
		cin >> c;
		string g;
		while (cin >> g) {
			if (g.back() == ',')
				g.erase(g.size() - 1);
			else
				break;
			//cout << ':' << g << ':' << endl;
			rev_m[g].pb(s);
		}
		rev_m[g].pb(s);
	}
	cout << rev_m.size() << endl;
	for (auto i : rev_m) {
		cout << i.fi << " - ";
		if (i.se.size() == 1)
			cout << i.se[0];
		else
			for (string j : i.se) {
				if (j != i.se[0])
					cout << ", ";
				cout << j;
			}
		cout << endl;
	}
	return 0;
}