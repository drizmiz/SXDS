
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
