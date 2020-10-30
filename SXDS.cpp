﻿
// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <iomanip>
#include <sstream>

#include <string>
#include <stack>

#include <cmath>

using namespace std;

class unit
{
	bool sign;
	char char_inside;
	double double_inside;
public:
	unit& operator=(const char c)
	{
		char_inside = c;
		sign = false;
		return *this;
	}
	unit& operator=(const double d)
	{
		double_inside = d;
		sign = true;
		return *this;
	}
	char get_char() const { return char_inside; }
	double get_double() const { return double_inside; }
	bool is_num() const { return sign; }
};

double calc(char op, double lhs, double rhs)
{
	switch (op)
	{
	case '+':
		return lhs + rhs; break;
	case '-':
		return lhs - rhs; break;
	case '*':
		return lhs * rhs; break;
	case '/':
		return lhs / rhs; break;
	default:
		return NAN; break;
	}
}

double lambda(const string& expr)
{
	stringstream ss(expr);
	string notation;

	stack<unit> notes;
	for (; ss >> notation;)
	{
		unit u;
		if (!isdigit(notation[0]))
			u = notation[0];
		else
		{
			u = stod(notation);

			for (; !notes.empty() && notes.top().is_num();)
			{
				unit lhs = notes.top();
				notes.pop();
				unit op = notes.top();
				notes.pop();
				u = calc(op.get_char(), lhs.get_double(), u.get_double());
			}
		}
		notes.push(u);
	}

	return notes.top().get_double();
}

int main()
{
	string s;
	getline(cin, s);
	cout << fixed << setprecision(6) << lambda(s) << endl;
}

#if false
int srch_regex(const string& str, const string& pattern)
{
	regex rg(pattern);
	smatch sm;
	if (!regex_search(str, sm, rg))
		return -1;
	else
		return sm.position();
}

int findn(const string& s)
{
	string needle;
	for (int i = 1; i <= s.size() / 2; ++i)
	{
		if (s.size() % i != 0)
			continue;
		needle = s.substr(0, i);
		bool flag = true;
		for (int j = i; j < s.size(); j++)
		{
			if (s[j] != needle[j % i])
			{
				flag = false;
				break;
			}
		}
		if (flag)
			return s.size() / i;
	}
	return 1;
}

string s;

int main()
{
	ios::sync_with_stdio(false);
	for (int c=1; ;++c)
	{
		int N;
		cin >> N;
		if (!N)
			break;
		s.resize(N, '\0');
		
		(void)(cin.get());
		for (size_t i = 0; i < N; ++i)
			s[i] = cin.get();

		cout << "Test case #" << c << endl;
		cout << findn(s) << endl;
	}
	return 0;
}
#endif