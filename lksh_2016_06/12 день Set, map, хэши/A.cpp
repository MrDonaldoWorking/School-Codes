#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <queue>
#include <fstream>
#include <set>
#include <string>
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
	set<int> s;
	int x;
	while (cin >> x) {
		if (s.count(x) == 0)
			cout << "NO";
		else
			cout << "YES";
		cout << endl;
		s.insert(x);
	}
	return 0;
}