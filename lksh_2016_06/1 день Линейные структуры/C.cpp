#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define ll long long
#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
using namespace std;

int t = 0;
vector<int> a(100);

int main() {
	//ifstream in("reverse.in");
	//ofstream out("reverse.out");
	string s;
	int x, y;
	getline(cin, s);
	forn(i, 0, s.size()) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[t] = s[i] - '0';
			t++;
		}
		else if (s[i] != ' ') {
			t--;
			x = a[t];
			t--;
			y = a[t];
			if (s[i] == '+') a[t] = x + y;
			if (s[i] == '-') a[t] = y - x;
			if (s[i] == '*') a[t] = x * y;
			t++;
			//forn(i, 0, a.size())
			//	cout << a[i] << ' ';
			//cout << endl;
		}
	}
	cout << a[0];
	return 0;
}