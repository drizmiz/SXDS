// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>     // ���������ͷ�ļ�
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
