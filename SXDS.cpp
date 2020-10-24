// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>     // 输入输出流头文件
#include <string>
#include <iomanip>

using namespace std;

string encode(const string& s)
{
	string ret;
	for (auto c : s)
		if (c >= 'a' && c <= 'z')
			ret.push_back('a' + (c - 'a' + 1) % 26);
		else if (c >= 'A' && c <= 'Z')
			ret.push_back('A' + (c - 'A' + 1) % 26);
		else
			ret.push_back(c);
	return move(ret);
}

int main()
{
	size_t n = 0;
	cin >> n;
	(void)(cin.get());

	for (size_t i = 0; i < n; i++)
	{
		string s;
		getline(cin, s);
		cout << encode(s) << endl;
	}
}

#if false
int findn(const string& s)
{
	string needle;
	for (int i = 1; i <= s.size() / 2; ++i)
	{
		if (s.size() % i != 0)
			continue;
		needle = s.substr(0, i);
		bool flag = true;
		for (int j = i; j < s.size(); j++)
		{
			if (s[j] != needle[j % i])
			{
				flag = false;
				break;
			}
		}
		if (flag)
			return s.size() / i;
	}
	return 1;
}

string s;

int main()
{
	ios::sync_with_stdio(false);
	for (int c=1; ;++c)
	{
		int N;
		cin >> N;
		if (!N)
			break;
		s.resize(N, '\0');
		
		(void)(cin.get());
		for (size_t i = 0; i < N; ++i)
			s[i] = cin.get();

		cout << "Test case #" << c << endl;
		cout << findn(s) << endl;
	}
	return 0;
}
#endif