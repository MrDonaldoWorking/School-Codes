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
int main() {
	//ifstream cin("saloon.in");
	//ofstream cout("saloon.out");
	int n;
	queue <int> q;
	cin >> n;
	forn(i, 0, n) {
		int h, m, k, time;
		cin >> h >> m >> k;
		time = h * 60 + m;
		while (!q.empty() && q.front() <= time)
				q.pop();
		if (q.size() > k) 
			cout << h << ' ' << m << endl;
		else {
			int x;
			if (q.empty()) {
				x = time + 20;
				cout << x / 60 << ' ' << x % 60 << endl;
			}
			else {
				x = q.back() + 20;
				cout << x / 60 << ' ' << x % 60 << endl;
			}
			q.push(x);
		}
	}
	return 0;
}