/*#include <algorithm>
#include <allocators>
#include <array>
#include <atomic>
#include <bitset>
#include <cassert>
#include <ccomplex>
#include <cctype>
#include <cerrno>
#include <cfenv>
#include <cfloat>
#include <chrono>
#include <cinttypes>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <codecvt>
#include <complex>
#include <condition_variable>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstdbool>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctgmath>
#include <ctime>
#include <cuchar>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <filesystem>
#include <forward_list>
#include <fstream>
#include <functional>
#include <future>
#include <hash_map>
#include <hash_set>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <listing.inc>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <ostream>
#include <queue>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <set>
#include <shared_mutex>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <strstream>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
#include <xcomplex>
#include <xfacet>
#include <xfunctional>
#include <xhash>
#include <xiosbase>
#include <xlocale>
#include <xlocbuf>
#include <xlocinfo>
#include <xlocmes>
#include <xlocmon>
#include <xlocnum>
#include <xloctime>
#include <xmemory>
#include <xmemory0>
#include <xstddef>
#include <xstring>
#include <xtr1common>
#include <xtree>
#include <xxatomic>*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <queue>
#include <deque>
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
	int n, u;
	cin >> n;
	char s;
	deque<int> a;
	queue<int> b;
	forn(i, 0, n) {
		cin >> s;
		if (s != '-')
			cin >> u;
		if (s == '+')
			a.push_back(u);
		if (s == '*') {
			if (a.size() < b.size())
				a.push_front(u);
			else b.push(u);
		}
		if (s == '-') {
			cout << b.front() << endl;
			b.pop();
		}
		if (a.size() > b.size()) {
			b.push(a.front());
			a.pop_front();
		}
	}
	return 0;
}