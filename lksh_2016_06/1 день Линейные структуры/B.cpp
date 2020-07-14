#include <iostream>
//#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#define ll long long
#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
using namespace std;

int t = 0, xd = 0;
vector<int> a;

void push(int x) {
	a[t] = x;
	t++;
}

void pop(int x) {
	if (t > 0) t--;
	else {
		xd = 1;
		return;
	}
	if (abs(x) == a[t]) xd = 0;
	else xd = 1;
}

int main() {
	//ifstream in("reverse.in");
	//ofstream out("reverse.out");
	string s;
	cin >> s;
	a = vector<int>(100000);
	forn(i, 0, s.size()) {
		if (s[i] == '(') push(1);
		if (s[i] == '[') push(2);
		if (s[i] == '{') push(3);
		if (s[i] == ')') pop(-1);
		if (s[i] == ']') pop(-2);
		if (s[i] == '}') pop(-3);
		if (xd == 1) break;
	}
	if (xd == 1) cout << "NO";
	else if (t) cout << "NO";
	else cout << "YES";
	return 0;
}