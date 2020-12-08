﻿
// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
//#include <iomanip>
//#include <sstream>

#include <string>
//#include <string_view>
//#include <stack>
#include <vector>
//#include <deque>
//#include <queue>

//#include <map>
//#include <unordered_map>

#include <algorithm>
//#include <functional>
#include <type_traits>

//#include <limits>

#include <cassert>

using namespace std;

class weighted_uf
{
private:
	vector<int> parent;
	vector<size_t> sz;	// size of tree
	int cnt;
public:
	void remake(int N)
	{
		cnt = N;
		parent.resize(N);
		for (size_t i = 0; i < N; i++)
			parent[i] = i;
		sz.resize(N);
		fill(sz.begin(), sz.end(), 1);
	}
	weighted_uf(int N) { remake(N); }
	size_t tree_count() const { return cnt; }
	int find_root(int p) const
	{
		for (; p != parent[p]; p = parent[p]);
		return p;
	}
	bool connected(int p, int q) { 
		return find_root(p) == find_root(q);
	}
	void link(int p, int q)
	{
		int proot = find_root(p);
		int qroot = find_root(q);
		if (proot == qroot)return;
		if (sz[proot] < sz[qroot]) {
			parent[proot] = qroot;
			sz[qroot] += sz[proot];
		}
		else {
			parent[qroot] = proot;
			sz[proot] += sz[qroot];
		}
		--cnt;
	}
};

int main()
{
	for (int cs = 1;; ++cs)
	{
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		weighted_uf wuf(n);
		for (int ix = 0; ix < m; ++ix)
		{
			int i, j;
			cin >> i >> j;
			wuf.link(i - 1, j - 1);
		}
		cout << "Case " << cs << ": "
			<< wuf.tree_count() << endl;
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