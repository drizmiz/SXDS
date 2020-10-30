
// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>     // 输入输出流头文件
#include <string>
#include <vector>

using namespace std;

class needle
{
private:
	string pattern;
	vector<int> next;
public:
	friend class KMP_srcher;
	needle(const string& pattern) : next(pattern.size() + 1)
	{
		this->pattern = pattern;
		if (pattern.size())
		{
			next[0] = -1;

			int i = 0, j = -1;
			for (; i < pattern.size();)
			{
				if (j >= 0 && pattern[i] != pattern[j])
					j = next[j];
				else {
					++i; ++j;
					//if (pattern[i] == pattern[j])
						//next[i] = next[j];
					//else
					next[i] = j;
				}
			}
		}
	}
};

class KMP_srcher
{
public:
	static int search(const string& str, const needle& ndl)
	{
		const string& pat = ndl.pattern;

		int i = 0, j = 0;
		for (; i < (int)str.size() && j < (int)pat.size();)
		{
			if (j == -1 || str[i] == pat[j])
			{
				++i; ++j;
			}
			else j = ndl.next[j];
		}

		if (j < pat.size())
			return -1;
		else return i - j;
	}
};

int main()
{
	size_t t;
	cin >> t;
	for (; t--;)
	{
		string S, T;
		cin >> S >> T;
		cout << KMP_srcher::search(S, needle(T)) << endl;
	}
}