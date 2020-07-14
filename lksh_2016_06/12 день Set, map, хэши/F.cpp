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
	string s;
	cin >> s;
	//cout << s.size() << endl;
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
	hash1[0] = 0;
	hash2[0] = 0;
	forn(i, 1, s.size() + 1) {
		hash1[i] = (hash1[i - 1] * P) % M1;
		hash1[i] = (hash1[i] + s[i - 1]) % M1;
		hash2[i] = (hash2[i - 1] * P) % M2;
		hash2[i] = (hash2[i] + s[i - 1]) % M2;
		//cout << hash1[i] << ' ' << hash2[i] << endl;
		//cout << ha(i - 1, i, M1, hash1, power1) << ' ';
		//cout << ha(i - 1, i, M1, hash1, power1) << endl;  
	}
	//cout << endl;
	int n;
	cin >> n;
	forn(i, 0, n) {
		int leftone, rightone, lefttwo, righttwo;
		cin >> leftone >> rightone >> lefttwo >> righttwo;
		leftone--;
		lefttwo--;
		if (rightone - leftone != righttwo - lefttwo)
			cout << '-';
		else {
			if (ha(leftone, rightone, M1, hash1, power1) == ha(lefttwo, righttwo, M1, hash1, power1)) {
				if (ha(leftone, rightone, M2, hash2, power2) == ha(lefttwo, righttwo, M2, hash2, power2))
					cout << '+';
				else
					cout << '-';
			}
			else
				cout << '-';
		}
		/*cout << (hash1[rightone] % M1 - hash1[leftone] * power1[rightone - leftone] % M1) % M1 << ' ';
		cout << (hash1[righttwo] % M1 - hash1[lefttwo] * power1[righttwo - lefttwo] % M1) % M1 << endl;
		cout << (hash2[rightone] % M2 - hash2[leftone] * power2[rightone - leftone] % M2) % M2 << ' ';
		cout << (hash2[righttwo] % M2 - hash2[lefttwo] * power2[righttwo - lefttwo] % M2) % M2 << endl;
		cout << endl;
		cout << "----------------------------------------------" << endl;
		cout << "before" << endl;
		cout << hash1[rightone] << " - " << hash1[leftone] << " * " << power1[rightone - leftone] << " = " << (hash1[rightone] % M1 - hash1[leftone] * power1[rightone - leftone] % M1) % M1 << endl;
		cout << hash1[righttwo] << " - " << hash1[lefttwo] << " * " << power1[righttwo - lefttwo] << " = " << (hash1[righttwo] % M1 - hash1[lefttwo] * power1[righttwo - lefttwo] % M1) % M1 << endl;
		cout << hash2[rightone] << " - " << hash2[leftone] << " * " << power2[rightone - leftone] << " = " << (hash2[rightone] % M2 - hash2[leftone] * power2[rightone - leftone] % M2) % M2 << endl;
		cout << hash2[righttwo] << " - " << hash2[lefttwo] << " * " << power2[righttwo - lefttwo] << " = " << (hash2[righttwo] % M2 - hash2[lefttwo] * power2[righttwo - lefttwo] % M2) % M2 << endl;
		cout << "----------------------------------------------" << endl;
		cout << "after" << endl;
		cout << ha(leftone, rightone, M1, hash1, power1) << endl;
		cout << ha(lefttwo, righttwo, M1, hash1, power1) << endl;
		cout << ha(leftone, rightone, M2, hash2, power2) << endl;
		cout << ha(lefttwo, righttwo, M2, hash2, power2) << endl;
		cout << "----------------------------------------------" << endl;*/
	}
	return 0;
}
//abcdefghijklmnopqrstuvwxyz