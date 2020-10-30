// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int Calc[20][20]; // DP

int calc(size_t n)
{
	for (size_t ss = 0; ss <= n; ++ss)
		Calc[0][ss] = 1;
	for (size_t N = 1; N <= n; ++N)
	{
		Calc[N][0] = Calc[N - 1][1];
		for (size_t ss = 1; ss <= n - N; ++ss)
			Calc[N][ss] = Calc[N - 1][ss + 1] + Calc[N][ss - 1];
	}
	return Calc[n][0];
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", calc(n));
}

#if false
int srch_regex(const string& str, const string& pattern)
{
	regex rg(pattern);
	smatch sm;
	if (!regex_search(str, sm, rg))
		return -1;
	else
		return sm.position();
}

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