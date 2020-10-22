
// ****
// ***************************
// 此题和1.5完全相同
// ***************************
// ****

// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>     // 输入输出流头文件
#include <algorithm>    // 算法库
#include <list>		// 链表
#include <vector>	// 顺序存储的顺序表
#include <map>		

using namespace std;

int main()
{
	using coefc = int;
	using expo = int;

	int n;
	cin >> n;
	list<int> a;

	for (size_t i = 0; i < n; i++)
	{
		map<expo, coefc, greater<int>> m;

		for (int sign = 0; sign < 2; ++sign)
		{
			for (;;)
			{
				int c, e;
				cin >> c >> e;

				if (e < 0)break;

				if (m.find(e) != m.end())
				{
					m[e] += c;
				}
				else
				{
					m[e] = c;
				}
			}
		}

		bool flag = true;

		for (auto pair : m)
		{
			if (pair.second != 0)
			{
				if (!flag)
					cout << ' ';
				flag = false;

				cout << "[ " << pair.second << ' ' << pair.first << " ]";
			}
		}
		cout << endl;
	}
}