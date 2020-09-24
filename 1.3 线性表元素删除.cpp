// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>     // 输入输出流头文件
#include <algorithm>    // 算法库
#include <list>		// 链表

using namespace std;

int geti()
{
	int i;
	cin >> i;
	return i;
}

int main()
{
	int c = 0;
	cin >> c;
	for (size_t _i = 0; _i < c; _i++)
	{
		int n, x;
		cin >> n >> x;

		list<int> input;
		for (size_t i = 0; i < n; i++)
			input.push_back(geti());

		input.remove_if([=](int nx) {return nx > x; });

		for (auto i = input.begin(); i != input.end(); ++i)
		{
			if (i != input.begin())
				cout << ' ';
			cout << *i;
		}
		cout << endl;
	}
	return 0;
}
