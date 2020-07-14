#define _CRT_SECURE_NO_WARNINGS 
#pragma comment(linker, "/STACK:108777216") 

#include <iostream> 
#include <stdio.h>
#include <deque>
#include <vector> 
#include <algorithm> 
#include <set>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, b) for (int i = a; i < b; i++) 
#define form(i, a, b) for (int i = a - 1; i >= b; i--) 
#define all(a) a.begin(), a.end() 

template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

using namespace std;

static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

vector<ll> a;
ll n, x, y;

bool f(ll k) {
	ll q = k * y, ans = 0;
	forn(i, 0, n) {
		if (a[i] - q > 0)
			ans += (a[i] - q) / (x - y) + ((a[i] - q) % (x - y) > 0 ? 1 : 0);
	}

	if (ans > k)
		return false;
	return true;
}

int main() {
	freopen("boss.in", "r", stdin);
	freopen("boss.out", "w", stdout);

	scanf("%lld%lld%lld", &n, &x, &y);

	a.resize(n);
	forn(i, 0, n)
		scanf("%lld", &a[i]);

	if (x == y) {
		int max_ = -1;
		forn(i, 0, n)
			amax(max_, a[i]);
		printf("%lld", max_ / x + (max_ % x > 0 ? 1 : 0));
		return 0;
	}

	//sort(all(a));

	ll left = 0, right = 1e9, middle;
	while (right - left > 1) {
		middle = (left + right) / 2;
		if (f(middle))
			right = middle;
		else
			left = middle;
	}

	printf("%lld", right);

	return 0;
}