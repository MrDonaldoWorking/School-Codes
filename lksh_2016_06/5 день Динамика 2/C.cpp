#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
typedef long long ll;
typedef unsigned long long ull;
#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
#define pb push_back
#define po pop_back
#define fi first
#define se second
using namespace std;

const int INF = 1e9, NOMINALIC_LIMIT = 1000001;

int main() {
	int n;
	cin >> n;

	vector<int> nominal(n);
	forn(i, 0, n)
		cin >> nominal[i];

	int sum;
	cin >> sum;
	vector<int> dinamic(NOMINALIC_LIMIT, INF);
	//forn(i, 1, NOMINALIC_LIMIT)
	//	dinamic[i] = INF;
	forn(i, 1, n)
		dinamic[nominal[i]] = 1;
	dinamic[0] = 0;

	forn(i, 0, sum + 1)
		forn(j, 0, n)
		if (i - nominal[j] >= 0) {
			dinamic[i] = min(dinamic[i], dinamic[i - nominal[j]] + 1);
			//cout << 1;
		}

	//forn(i, 0, sum)
	//	cout << i << ' ' << dinamic[i] << endl;

	if (dinamic[sum] == INF) {
		dinamic[sum] = -1;
	}
	cout << dinamic[sum] << endl;

	if (dinamic[sum] == -1)
		sum = 0;
	while (sum > 0) {
		forn(i, 0, n)
			if (sum >= nominal[i] && dinamic[sum] - 1 == dinamic[sum - nominal[i]]) {
				cout << nominal[i] << ' ';
				sum -= nominal[i];
				break;
			}
	}

	return 0;
}