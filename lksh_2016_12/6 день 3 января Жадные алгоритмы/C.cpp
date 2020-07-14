#include <fstream>
#include <iostream>
#include <vector>
#include <string>

typedef long long ll;

using namespace std;

ifstream in("indic.in");
ofstream out("indic.out");

void System_error() {
	out << "NO SOLUTION";
	exit(0);
}

bool correct_number(vector<short> &hours, int &copyk, int &copyn, string &ans, int j) {
	if (copyk - hours[j] >= hours[1] * (copyn - 1) && copyk - hours[j] <= hours[8] * (copyn - 1)) {
		ans += j + '0';
		copyk -= hours[j];
		copyn--;
		return true;
	}

	return false;
}

int main() {
	int n, k;
	in >> n >> k;

	vector<short> hours(10);
	hours = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

	if (hours[1] * n > k || hours[8] * n < k)
		System_error();

	string ans_min;
	int copyk = k, copyn = n;
	for (int i = 0; i < n; i++) {
		int start = (i == 0 ? 1 : 0);
		for (int j = start; j < 10; j++)
			if (correct_number(hours, copyk, copyn, ans_min, j))
				break;
	}

	string ans_max;
	copyk = k, copyn = n;
	for (int i = 0; i < n; i++) {
		int start = (i == 0 ? 1 : 0);
		for (int j = 9; j >= start; j--)
			if (correct_number(hours, copyk, copyn, ans_max, j))
				break;
	}

	out << ans_min << '\n' << ans_max;

	return 0;
}