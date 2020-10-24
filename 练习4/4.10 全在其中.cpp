// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>     // 输入输出流头文件
#include <string>
#include <iomanip>

using namespace std;

using str_it = string::const_iterator;

bool substr(str_it s_begin, str_it s_end,
	str_it t_begin, str_it t_end)
{
	if (s_begin == s_end)
		return true;
	if (s_end - s_begin > t_end - t_begin)
		return false;
	if (*s_begin == *t_begin)
		return substr(s_begin + 1, s_end, t_begin + 1, t_end);
	else
		return substr(s_begin, s_end, t_begin + 1, t_end);
}

bool substr(const string& s, const string& t)
{
	return substr(s.cbegin(), s.cend(), t.cbegin(), t.cend());
}

int main()
{
	string s, t;
	for (; cin >> s >> t;)
	{
		if (substr(s, t))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}