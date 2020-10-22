
// ****
// ***************************
// �����1.5��ȫ��ͬ
// ***************************
// ****

// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>     // ���������ͷ�ļ�
#include <algorithm>    // �㷨��
#include <list>		// ����
#include <vector>	// ˳��洢��˳���
#include <map>		

using namespace std;

int main()
{
	using coefc = int;
	using expo = int;

	int n;
	cin >> n;
	list<int> a;

	for (size_t i = 0; i < n; i++)
	{
		map<expo, coefc, greater<int>> m;

		for (int sign = 0; sign < 2; ++sign)
		{
			for (;;)
			{
				int c, e;
				cin >> c >> e;

				if (e < 0)break;

				if (m.find(e) != m.end())
				{
					m[e] += c;
				}
				else
				{
					m[e] = c;
				}
			}
		}

		bool flag = true;

		for (auto pair : m)
		{
			if (pair.second != 0)
			{
				if (!flag)
					cout << ' ';
				flag = false;

				cout << "[ " << pair.second << ' ' << pair.first << " ]";
			}
		}
		cout << endl;
	}
}