// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>     // 输入输出流头文件
#include <algorithm>    // 算法库
#include <vector>		// vector

using namespace std;

int main()
{
	int c = 0;
	cin >> c;
	for (size_t _i = 0; _i < c; _i++)
	{
		int n, x, y;
		cin >> n >> x >> y;

		vector<int> input(n);
		for (size_t i = 0; i < n; i++)
			cin >> input[i];

		reverse(input.begin(), input.end());

		for (size_t i = 0; i < n; i++)
			if (input[i] > x&& input[i] < y)
			{
				cout << input[i - 1] << ' '
					<< input[i + 1] << endl;
				break;
			}
	}
}
