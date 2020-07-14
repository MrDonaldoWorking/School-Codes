#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

#define forn(i, a, b) for (int i = int(a); i < int(b); i++)
#define form(i, a, b) for (int i = int(a) - 1; i >= int(b); i--)
#define sz(a) (int)a.size()
#define all(x) x.begin(), x.end()
#define input fxheklwucgfiurwanguilvwe

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ifstream in("expr2.in");
ofstream out("expr2.out");

struct lexem {
	enum {
		LBracket,
		RBracket,
		plus,
		minus,
		multiplication,
		number,
		end_of_expression,
		Podarok
	} 
	type;
	ll value;
};

int curr_index;
lexem curr_lexem;
const ll INF = 1e17;

void System_error(string &my_expression) {
	out << "WRONG" << ", " << my_expression[curr_index] << ' ' << curr_index;
	exit(0);
}

int stringtoint(string &s) {
	int ans = 0, k = 1;

	form(i, s.size(), 0) {
		ans += (s[i] - '0') * k;
		k *= 10;
	}

	return ans;
}

void winter_club(string &s, string &my_expression) {
	if (s == "Ded Moroz")
		curr_lexem = { lexem::number, 2016 };
	else {
		if (s == "Snegurochka")
			curr_lexem = { lexem::number, 10 };
		else {
			if (s == "Moroz")
				curr_lexem = { lexem::number, -30 };
			else {
				if (s == "Podarok")
					curr_lexem.type = lexem::Podarok;
				else
					System_error(my_expression);
			}
		}
	}
}

bool is_char(char &c) {
	if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c == ' ')
		return true;
	return false;
}

bool digit(char &c) {
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

ll present(ll n) {
	if (n > 0)
		return n + 5;
	return -n;
}

void input_const_words(string &input, char &c) {
	input += '(';
	while (is_char(c)) {
		input += c;
		in >> c;
	}
	input += ')';
}

void input_numbers(string &input, char &c) {
	input += '(';
	while (digit(c)) {
		input += c;
		in >> c;
	}
	input += ')';
}

void symbol(char &c, string &my_expression) {
	if (c == '+')
		curr_lexem.type = lexem::plus;
	else {
		if (c == '-')
			curr_lexem.type = lexem::minus;
		else {
			if (c == '(')
				curr_lexem.type = lexem::LBracket;
			else {
				if (c == ')')
					curr_lexem.type = lexem::RBracket;
				else {
					if (c == '*')
						curr_lexem.type = lexem::multiplication;
					else
						System_error(my_expression);
				}
			}
		}
	}
}

void next_lexem(string &my_expression) {
	if (curr_index == my_expression.size() - 1)
		curr_lexem.type = lexem::end_of_expression;

	else {
		if (digit(my_expression[curr_index])) {
			string num = "";
			while (digit(my_expression[curr_index])) {
				num += my_expression[curr_index];
				curr_index++;
			}
			curr_lexem = { lexem::number, stringtoint(num) };
		}

		else {
			if (is_char(my_expression[curr_index])) {
				string character = "";
				while (is_char(my_expression[curr_index])) {
					character += my_expression[curr_index];
					curr_index++;
				}
				winter_club(character, my_expression);
			}

			else {
				symbol(my_expression[curr_index], my_expression);
				curr_index++;
			}
		}
	}
}

/*void prev_lexem(string &my_expression) {
	if (digit(my_expression[curr_index])) {
		string num = "";
		while (digit(my_expression[curr_index])) {
			num += my_expression[curr_index];
			curr_index--;
		}
		reverse(num.begin(), num.end());
		curr_lexem = { lexem::number, stringtoint(num) };
	}

	else {
		if (is_char(my_expression[curr_index])) {
			string character = "";
			while (is_char(my_expression[curr_index])) {
				character += my_expression[curr_index];
				curr_index--;
			}
			winter_club(character, my_expression);
		}

		else {
			symbol(my_expression[curr_index], my_expression);
			curr_index--;
		}
	}
}*/

ll multiplier(string &my_expression);
ll addendum(string &my_expression);
ll expression(string &my_expression);

ll addendum(string &my_expression) {
	ll result = multiplier(my_expression);

	if (curr_lexem.type == lexem::multiplication) {
		next_lexem(my_expression);
		result *= addendum(my_expression);
	}

	return result;
}

ll expression(string &my_expression) {
	ll result = addendum(my_expression);

	if (curr_lexem.type == lexem::plus) {
		next_lexem(my_expression);
		result += expression(my_expression);
	}
	
	return result;
}

ll multiplier(string &my_expression) {
	ll result = INF;

	if (curr_lexem.type == lexem::number) {
		result = curr_lexem.value;
		next_lexem(my_expression);
	}

	else {
		if (curr_lexem.type == lexem::Podarok) {
			next_lexem(my_expression);
			result = present(expression(my_expression));

			/*if (curr_lexem.type == lexem::RBracket)
				next_lexem(my_expression);
			else
				System_error(my_expression);*/
		}
		else {
			if (curr_lexem.type == lexem::minus) {
				next_lexem(my_expression);
				result = -multiplier(my_expression);
			}
			else {
				if (curr_lexem.type == lexem::LBracket) {
					next_lexem(my_expression);
					result = expression(my_expression);

					//if (curr_lexem.type == lexem::RBracket)
					next_lexem(my_expression);
					//else
					//	System_error(my_expression);
				}
			}
		}
	}

	if (result == INF)
		System_error(my_expression);

	return result;
}

int main() {
	stack<int> bracket;
	string input;
	//getline(in, input);
	char c;
	int brackets = 0, presents = 0;
	in >> noskipws;
	while (in >> c) {
		if (c == 'D' || c == 'M' || c == 'S')
			input_const_words(input, c);
		if (digit(c))
			input_numbers(input, c);
		if (c == 'P') {
			input += '(';
			presents++;
			while (is_char(c)) {
				input += c;
				in >> c;
			}
			if (input.back() != 'k' || c != '(')
				System_error(input);
		}
		
		if (c == '.')
			break;
		
		if (!input.empty() && c == '-') {
			if (input.back() == '-' || input.back() == '+' || input.back() == '*')
				System_error(input);
		}

		if (c == '(') {
			bracket.push(1);
			brackets++;
		}
		if (c == ')') {
			if (bracket.empty())
				System_error(input);
			bracket.pop();
			brackets--;
		}

		if (brackets == presents - 1 && presents > 0) {
			input += ')';
			presents--;
		}

		input += c;
	}

	//cout << input << endl;

	if (!bracket.empty())
		System_error(input);

	string my_expression;
	forn(i, 0, int(input.size())) {
		if (input[i] == '-') {
			if (my_expression.empty())
				my_expression += "(-1)*";

			else {
				if (my_expression.back() == '(')
					my_expression += "0+(-1)*";

				else
					my_expression += "+(-1)*";
			}
		}
		else
			my_expression += input[i];
	}
	my_expression += '.';
	//cout << my_expression;

	curr_index = 0;
	next_lexem(my_expression);

	ll result_of_expression;
	result_of_expression = expression(my_expression);

	if (curr_index != my_expression.size() - 1)
		System_error(my_expression);
	else
		out << result_of_expression;

	return 0;
} 