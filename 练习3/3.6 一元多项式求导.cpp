
// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>     // 输入输出流头文件
#include <algorithm>    // 算法库
#include <list>		// 链表
#include <vector>	// 顺序存储的顺序表
#include <map>		
#include <sstream>
#include <string>

using namespace std;

int main()
{
	using coefc = int;
	using expo = int;

	list<int> a;

	// 垃圾openjudge，输入最后居然没有换行符
	for (; !cin.eof();)
	{
		map<expo, coefc, greater<int>> m;

		string bufs;
		getline(cin, bufs);

		stringstream buf(bufs);

		for (; !buf.eof();)
		{
			int c, e;
			buf >> c >> e;

			c *= e;
			if (e > 0)
				e -= 1;

			if (m.find(e) != m.end())
			{
				m[e] += c;
			}
			else
			{
				m[e] = c;
			}
		}

		bool no_output = true;

		for (auto pair : m)
		{
			if (pair.second != 0)
			{
				if (!no_output)
				{
					cout << ' ';
				}

				no_output = false;
				cout << pair.second << ' ' << pair.first;
			}
		}

		if (no_output)
			cout << "0 0";

		cout << endl;
	}
}