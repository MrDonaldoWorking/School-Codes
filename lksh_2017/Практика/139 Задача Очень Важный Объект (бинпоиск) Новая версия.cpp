#define _CRT_SECURE_NO_WARNINGS 
#pragma comment(linker, "/STACK:108777216") 

#include <iostream> 
#include <fstream> 
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
const double EPS = 1e-7;

struct point {
	ld x;
	ld y;
};

int n, k;
ld l;
set<int> holes;
vector<int> holev;
vector<ld> holelength;
vector<ld> length;
vector<ld> sumlength;

ld f(int i) {
	///Circumvention
	int left = i, right = 2 * n, middle;
	while (right - left > 1) {
		middle = (left + right) / 2;
		if (l - sumlength[middle] + sumlength[i] > EPS)
			left = middle;
		else
			right = middle;
	}

	ld ans = 0;
	ans = holelength[left] - holelength[i];
	if (holes.count(left % n + 1))
		ans += l - sumlength[left] + sumlength[i];

	///Opposite Circumvention
	left = i, right = 2 * n;
	while (right - left > 1) {
		middle = (left + right) / 2;
		if (l - sumlength[i + n] + sumlength[middle] > EPS)
			right = middle;
		else
			left = middle;
	}

	ld ans1 = 0;
	ans1 = holelength[i + n] - holelength[left];
	if (holes.count(left % n + 1))
		ans1 += l - sumlength[i + n] + sumlength[left];

	return max(ans, ans1);
}

int main() {
	ios::sync_with_stdio(false);

	ifstream in("fence.in");
	ofstream out("fence.out");

	in >> n >> l >> k;

	holev.resize(k);
	forn(i, 0, k) {
		int x;
		in >> x;
		holes.insert(x);
		holev[i] = x;
	}

	vector<point> polygon(n);
	forn(i, 0, n)
		in >> polygon[i].x >> polygon[i].y;
	polygon.push_back(polygon[0]);

	length.resize(n, 0);
	forn(i, 0, n) {
		length[i] = (polygon[i].x - polygon[i + 1].x) * (polygon[i].x - polygon[i + 1].x);
		length[i] += (polygon[i].y - polygon[i + 1].y) * (polygon[i].y - polygon[i + 1].y);
		length[i] = sqrt(length[i]);
	}

	sumlength.resize(2 * n + 1);
	sumlength[0] = 0;
	forn(i, 1, n + 1)
		sumlength[i] = sumlength[i - 1] + length[i - 1];
	forn(i, n + 1, 2 * n + 1)
		sumlength[i] = sumlength[i - 1] + length[i - n - 1];

	holelength.resize(2 * n + 1, 0);
	holelength[0] = 0;
	int j = 0;
	forn(i, 1, n + 1) {
		holelength[i] = holelength[i - 1];
		if (j < k && holev[j] == i) {
			holelength[i] += length[i - 1];
			j++;
		}
	}
	forn(i, n + 1, 2 * n + 1)
		holelength[i] = holelength[i - n] + holelength[n];

	ld sumhole = 0;
	for (int i : holes)//i -> hole[i]
		sumhole += length[i - 1];

	ld sum = sumlength[n - 1];

	out.precision(20);
	out << fixed;

	if (l - sum > EPS) {
		out << EPS / EPS - 1;//0
		return 0;
	}

	ld max_ = 0;
	forn(i, 0, n)
		amax(max_, f(i));

	out << sumhole - max_;

	return 0;
}