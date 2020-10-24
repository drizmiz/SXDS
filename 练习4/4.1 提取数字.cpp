// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>     // 输入输出流头文件
#include <string>
#include <iomanip>

using namespace std;


int main()
{
	string s;
	getline(cin, s);

	for (auto c : s)
		if (c >= '0' && c <= '9')
			cout << setw(4) << c;

	cout << endl;
}
