// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>     // ���������ͷ�ļ�
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
