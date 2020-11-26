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

int up_bound(int m) //  ret>m
{
	int i = 0, n = 1;
	for (; n <= m; ++i) n <<= 1;
	return i;
}

int f(int m, int n)
{
	//int ret = 1;
	//if (n >= 2 * m)
	//{
	//	ret += f(2 * m, n);
	//	if (n >= 2 * m + 1)
	//		ret += f(2 * m + 1, n);
	//}
	//return ret;

	// 先算出层数
	int cm = up_bound(m);
	int cn = up_bound(n);

	int tmp = 1 << (cn - cm);
	// 这是除了最后一层
	int ret = tmp - 1;
	// 这是最后一层左边界
	int fst = m * tmp;
	// 这是最后一层尾后
	int lst = (m + 1) * tmp;
	if (n >= fst)
		if (n >= lst - 1)
			ret += lst - fst;
		else
			ret += n - fst + 1;
	return ret;
}

int main()
{
	for (;;)
	{
		int m, n;
		cin >> m >> n;
		// m=3, n=12
		if (!m && !n)
			break;
		cout << f(m, n) << endl;
	}
}
