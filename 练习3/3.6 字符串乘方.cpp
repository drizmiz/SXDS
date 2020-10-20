
#include <string>
#include <iostream>

using namespace std;

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
	for (; ;)
	{
		cin >> s;
		if (s == ".")
			break;
		cout << findn(s) << endl;
	}
	return 0;
}