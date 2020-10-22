
// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>     // ���������ͷ�ļ�
#include <algorithm>    // �㷨��
#include <list>		// ����
#include <vector>	// ˳��洢��˳���
#include <map>		
#include <sstream>
#include <string>

using namespace std;

int main()
{
	using coefc = int;
	using expo = int;

	list<int> a;

	// ����openjudge����������Ȼû�л��з�
	for (; !cin.eof();)
	{
		map<expo, coefc, greater<int>> m;

		string bufs;
		getline(cin, bufs);

		stringstream buf(bufs);

		for (; !buf.eof();)
		{
			int c, e;
			buf >> c >> e;

			c *= e;
			if (e > 0)
				e -= 1;

			if (m.find(e) != m.end())
			{
				m[e] += c;
			}
			else
			{
				m[e] = c;
			}
		}

		bool no_output = true;

		for (auto pair : m)
		{
			if (pair.second != 0)
			{
				if (!no_output)
				{
					cout << ' ';
				}

				no_output = false;
				cout << pair.second << ' ' << pair.first;
			}
		}

		if (no_output)
			cout << "0 0";

		cout << endl;
	}
}