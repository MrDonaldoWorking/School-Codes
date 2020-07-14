#include <fstream>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
#define sz(a) (int)a.size()
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
//typedef vector<int> vi;
//typedef vector<ll> vll;
//typedef vector<bool> vb;
//typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ifstream in("input.txt");
ofstream out("output.txt");

const int INF = int(1e9);

struct element {
	int value;
	int min_;
};

int main() {
	int n, k;
	in >> n >> k;

	stack<element> entry;
	int min_ = INF;
	forn(j, 0, k) {
		int x;
		in >> x;

		min_ = min(min_, x);
		entry.push({ x, min_ });
	}

	stack<element> escape;
	forn(i, 0, n - k + 1) {
		if (escape.empty()) {
			int min_ = INF;
			forn(i, 0, k) {
				element x = entry.top();
				entry.pop();

				min_ = min(min_, x.value);
				escape.push({ x.value, min_ });
			}
		}

		int ans = INF;
		if (!entry.empty())
			ans = min(ans, entry.top().min_);
		if (!escape.empty()) {
			ans = min(ans, escape.top().min_);
			escape.pop();
		}

		out << ans << endl;

		int min_;
		if (entry.empty())
			min_ = INF;
		else
			min_ = entry.top().min_;

		int x;
		in >> x;

		entry.push({ x, min(min_, x) });
	}

	return 0;
}