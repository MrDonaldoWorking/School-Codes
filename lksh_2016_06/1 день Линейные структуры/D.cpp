#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
typedef long long ll;
typedef unsigned long long ull;
#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
using namespace std;
int main() {
	//ifstream in("reverse.in");
	//ofstream out("reverse.out");
	int n, b, m, k = 0;
	stack<ll> a;
	cin >> n >> m;
	a.push(n);
	int g;
	while (!a.empty()) {
		b = a.top();
		a.pop();
		if (b / 2 > m)
			a.push(b / 2);
		else
			k++;
		g = b / 2 + b % 2;
		if (g > m)
			a.push(g);
		else
			k++;
	}
	cout << k;
	return 0;
}