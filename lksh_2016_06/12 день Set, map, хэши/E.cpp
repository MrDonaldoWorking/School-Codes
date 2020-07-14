#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <queue>
#include <set>
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
	int n;
	cin >> n;
	multiset<int> s;
	forn(i, 0, n) {
		int x;
		cin >> x;
		s.insert(x);
	}
	int sum;
	double answer = 0;
	while (s.size() > 1) {
		sum = *s.begin();
		s.erase(s.begin());
		sum += *s.begin();
		s.erase(s.begin());
		s.insert(sum);
		answer += sum * 5 / double(100);
	}
	cout << fixed;
	cout.precision(2);
	cout << answer;
	return 0;
}