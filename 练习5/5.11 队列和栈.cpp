
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

#include <algorithm>
#include <functional>

#include <limits>

using namespace std;

template<class _Cont>
void output(const _Cont& data)
{
	bool first = true;
	for (auto& i : data)
	{
		if (first)
		{
			cout << i;
			first = false;
		}
		else
			cout << " " << i;
	}
	cout << endl;
}

int main()
{
	int m = 0;
	cin >> m;
	for (; m--;)
	{
		queue<int> que;
		stack<int> stk;
		int n = 0;
		cin >> n;
		for (; n-- > 0;)
		{
			string s;
			cin >> s;
			if (s[1] == 'u')
			{
				int num;
				cin >> num;
				que.push(num);
				stk.push(num);
			}
			else
			{
				if (que.empty())
				{
					cout << "error" << endl;
					cout << "error" << endl;
					for (; n-- > 0;)
					{
						cin >> s;
						if (s[1] == 'u')
						{
							int num;
							cin >> num;
						}
					}
					n = -255;
				}
				else
				{
					que.pop();
					stk.pop();
				}
			}
		}
		if (n > -20)
		{
			vector<int> vec;
			for (; !que.empty(); que.pop())
				vec.push_back(que.front());
			output(vec);
			vec.clear();
			for (; !stk.empty(); stk.pop())
				vec.push_back(stk.top());
			reverse(vec.begin(), vec.end());
			output(vec);
		}
	}
}