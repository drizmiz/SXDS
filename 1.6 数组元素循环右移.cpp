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
	int N, M;
	cin >> N >> M;
	vector<int> vec(N);

	for (size_t i = 0; i < N; i++)
		cin >> vec[i];

	for (; M > N;)
		M -= N;

	rotate(vec.begin(), vec.begin() + N - M, vec.end());

	for (size_t i = 0; i < N; i++)
	{
		if (i)
			cout << ' ';
		cout << vec[i];
	}

	cout << endl;
	return 0;
}
