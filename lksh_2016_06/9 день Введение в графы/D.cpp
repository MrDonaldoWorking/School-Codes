#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <queue>
typedef long long ll;
typedef unsigned long long ull;
#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
#define pb push_back
#define po pop_back
#define fi first
#define se second
using namespace std;

const int INF = 2147483647;
const int NUMBER = 10000;

ll power(int x, int y) {
	ll s = 1;

	forn(i, 0, y)
		s *= x;

	return s;
}

int number(int x) {
	int s = 0;

	while (x > 0) {
		s += x % 10;
		x /= 10;
	}

	return s;
}

int main() {
	int n, m;
	cin >> n >> m;

	queue<int> b;
	bool used[NUMBER];
	forn(i, 0, NUMBER)
		used[i] = false;

	int distance[NUMBER];
	forn(i, 0, NUMBER)
		distance[i] = INF;

	distance[n] = 0;
	b.push(n);
	used[n] = true;

	while (!b.empty()) {
		auto bf = b.front();
		used[bf] = true;
		b.pop();

		if (bf == m)
			break;
		//cout << bf.fi << ' ';
		if (bf * 3 < NUMBER && !used[bf * 3]) {
			b.push(bf * 3);
			distance[bf * 3] = min(distance[bf] + 1, distance[bf * 3]);
			used[bf * 3] = true;
		}

		int g = number(bf);

		if (bf + g < NUMBER && !used[bf + g]) {
			b.push(bf + g);
			distance[bf + g] = min(distance[bf] + 1, distance[bf + g]);
			used[bf + g] = true;
		}

		if (bf > 1 && !used[bf - 2]) {
			b.push(bf - 2);
			distance[bf - 2] = min(distance[bf] + 1, distance[bf - 2]);
			used[bf - 2] = true;
		}
	}

	cout << distance[m];

	return 0;
}