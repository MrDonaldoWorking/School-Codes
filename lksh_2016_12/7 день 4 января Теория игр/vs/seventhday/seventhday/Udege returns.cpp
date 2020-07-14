#include <fstream>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
#define sz(a) (int)a.size()
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ifstream in("substring.in");
ofstream out("substring.out");

int mex(vector<int> &a) {
	set<int> b(a.begin(), a.end());
	for (int i = 0; ; i++)
		if (!b.count(i))
			return i;
}

int stringtoint(string s) {
	int ans = 0, k = 1;
	form(i, s.size(), 0) {
		ans += (s[i] - '0') * k;
		k *= 10;
	}

	return ans;
}

void substr(int n, vector<int> &ans) {
	string s;
	while (n > 0) {
		s += n % 10 + '0';
		n /= 10;
	}
	reverse(s.begin(), s.end());

	ans = {};

	forn(i, 0, s.size()) {
		if (s[i] == '0')
			continue;

		string g;
		forn(j, i, s.size()) {
			g += s[j];

			if (g == s)
				continue;

			ans.push_back(stringtoint(g));
		}
	}
}

int main() {
	int n;
	in >> n;

	vector<bool> g(n + 1, false);
	vector<int> numbers;
	forn(i, 10, n + 1) {
		substr(i, numbers);
		forn(j, 0, numbers.size())
			if (!g[i - numbers[j]])
				g[i] = true;
	}

	if (!g[n]) {
		out << -1;
		return 0;
	}

	substr(n, numbers);
	sort(all(numbers));
	forn(i, 0, numbers.size())
		if (!g[n - numbers[i]]) {
			out << numbers[i];
			break;
		}
	
	return 0;
}