#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
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

const int P = 239;
const ull M1 = 1e9 + 9, M2 = 1e9 + 7;

ull ha(ull left, ull right, ull div, vector<ull> &h, vector<ull> &p) {
	return (h[right] - (h[left] * p[right - left]) % div + (2 * div)) % div;
}

int main() {
	string s, s1;
	cin >> s >> s1;
	vector<ull> power1(s.size() + 1);
	vector<ull> power2(s.size() + 1);
	power1[0] = 1;
	power2[0] = 1;
	forn(i, 1, s.size() + 1) {
		power1[i] = (power1[i - 1] * P) % M1;
		power2[i] = (power2[i - 1] * P) % M2;
	}
	vector<ull> hash1(s.size() + 1);
	vector<ull> hash2(s.size() + 1);
	vector<ull> hash3(s1.size() + 1);
	vector<ull> hash4(s1.size() + 1);
	hash1[0] = 0;
	hash2[0] = 0;
	hash3[0] = 0;
	hash4[0] = 0;
	forn(i, 1, s.size() + 1) {
		hash1[i] = (hash1[i - 1] * P) % M1;
		hash1[i] = (hash1[i] + s[i - 1]) % M1;
		hash2[i] = (hash2[i - 1] * P) % M2;
		hash2[i] = (hash2[i] + s[i - 1]) % M2;
	}
	forn(i, 1, s1.size() + 1) {
		hash3[i] = (hash3[i - 1] * P) % M1;
		hash3[i] = (hash3[i] + s1[i - 1]) % M1;
		hash4[i] = (hash4[i - 1] * P) % M2;
		hash4[i] = (hash4[i] + s1[i - 1]) % M2;
	}
	/*forn(i, 0, s.size() + 1)
		cout << hash1[i] << ' ';
	cout << endl;
	forn(i, 0, s.size() + 1)
		cout << hash2[i] << ' ';
	cout << endl;
	forn(i, 0, s1.size() + 1)
		cout << hash3[i] << ' ';
	cout << endl;
	forn(i, 0, s1.size() + 1)
		cout << hash4[i] << ' ';
	cout << endl;*/
	int n;
	cin >> n;
	if (n > s.size() || n > s1.size()) {
		cout << "NO";
		return 0;
	}
	vector<ull> check11(s.size() - n + 1);
	vector<ull> check12(s.size() - n + 1);
	vector<ull> check21(s1.size() - n + 1);
	vector<ull> check22(s1.size() - n + 1);
	forn(i, 0, s.size() - n + 1) {
		check11[i] = (hash1[i + n] - (hash1[i] * power1[n]) % M1 + (2 * M1)) % M1;
		check12[i] = (hash2[i + n] - (hash2[i] * power2[n]) % M2 + (2 * M2)) % M2;
	}
	forn(i, 0, s1.size() - n + 1) {
		check21[i] = (hash3[i + n] - (hash3[i] * power1[n]) % M1 + (2 * M1)) % M1;
		check22[i] = (hash4[i + n] - (hash4[i] * power2[n]) % M2 + (2 * M2)) % M2;
	}
	/*forn(i, 0, s.size() - n + 1)
		cout << check11[i] << ' ';
	cout << endl;
	forn(i, 0, s.size() - n + 1)
		cout << check12[i] << ' ';
	cout << endl;
	forn(i, 0, s1.size() - n + 1)
		cout << check21[i] << ' ';
	cout << endl;
	forn(i, 0, s1.size() - n + 1)
		cout << check22[i] << ' ';
	cout << endl;*/
	sort(check11.begin(), check11.end());
	sort(check12.begin(), check12.end());
	sort(check21.begin(), check21.end());
	sort(check22.begin(), check22.end());
	int i = 0, j = 0;
	bool can = false;
	while (i < check11.size() && j < check22.size()) {
		if (check11[i] == check21[j] && check12[i] == check22[j]) {
			can = true;
			break;
		}
		if (check11[i] < check21[j])
			i++;
		else
			j++;
	}
	if (can)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}