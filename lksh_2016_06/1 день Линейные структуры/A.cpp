#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define ll long long
#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
using namespace std;
int main() {
	ifstream in("reverse.in");
	ofstream out("reverse.out");
	int n, x;
	vector<int> a;
	in >> n;
	forn(i, 0, n) {
		in >> x;
		a.push_back(x);
	}
	form(i, n, 0) out << a[i] << endl;
	return 0;
}