﻿
// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <iomanip>
#include <sstream>

#include <string>
#include <stack>
#include <vector>
#include <deque>
#include <queue>

#include <map>
#include <unordered_map>

#include <algorithm>
#include <functional>

#include <limits>

using namespace std;

const char nul = '0';

struct node
{
	char l = nul, r = nul;
};

size_t idx(const char c)
{
	return c - 'A';
}

vector<node> tree;

char reconstruct(const string& f, const string& m)
{
	if (f.empty())
		return nul;

	const char root = f[0];
	auto divider = m.find(root);
	string mleft = m.substr(0, divider);
	string mright = m.substr(divider + 1, m.size() - divider - 1);

	string fprime = f.substr(1, f.size() - 1);
	auto fleft = fprime.substr(0, divider);
	auto fright = fprime.substr(divider, m.size() - divider - 1);

	tree[idx(root)].l = reconstruct(fleft, mleft);
	tree[idx(root)].r = reconstruct(fright, mright);
	return root;
}

string b_order(char root)
{
	if (root == nul)return string();
	auto l = b_order(tree[idx(root)].l);
	auto r = b_order(tree[idx(root)].r);
	return l + r + root;
}

int main()
{
	for (;;)
	{
		string forder, morder;
		if (!(cin >> forder >> morder))
			break;
		tree.clear();
		tree.resize(26);
		reconstruct(forder, morder);
		cout << b_order(forder[0]) << endl;
	}
}

/*
using namespace std;

int exec(char op, int lhs, int rhs)
{
	switch (op)
	{
	case '+':
		return lhs + rhs;
	case '-':
		return lhs - rhs;
	case '*':
		return lhs * rhs;
	case '/':
		return lhs / rhs;
	default:
		throw exception((string("unknown operator ") + op).c_str());
	}
}

const map<char, int> pr_table{
	{'(', -1},
	{'+', 0},
	{'-', 0},
	{'*', 1},
	{'/', 1},
	{')', 255}
};

bool prior_to(char op1, char op2)
{
	return pr_table.at(op1) > pr_table.at(op2);
}

int calc(const string& expr)
{
	stack<int> nums;
	stack<char> ops;
	string tmp_num;
	for (auto& c : expr)
	{
		if (isdigit(c))
		{
			tmp_num.push_back(c);
			continue;
		}
		if (!tmp_num.empty())
		{
			nums.push(stoi(tmp_num));
			tmp_num.clear();
		}
		

	}
}

int main()
{
	
}
*/