// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>     // ���������ͷ�ļ�
#include <algorithm>    // �㷨��
#include <list>		// ����
#include <vector>	// ˳��洢��˳���

using namespace std;

struct stu
{
	int id;
	string name;
	int score;
};

istream& operator>>(istream& is, stu& s)
{
	is >> s.id >> s.name >> s.score;
	return is;
}

ostream& operator<<(ostream& os, const stu& s)
{
	os << s.id << ' ' << s.name << ' ' << s.score;
	return os;
}

stu getstu()
{
	stu i;
	cin >> i;
	return i;
}

int main()
{
	const int n = 12, m = 13;
	list<stu> lst1, lst2;

	for (size_t i = 0; i < n; i++)
		lst1.push_back(getstu());
	for (size_t i = 0; i < m; i++)
		lst2.push_back(getstu());

	lst1.merge(lst2, [](stu& o) {score > o.score});

	for (auto i : lst1)
		cout << i << endl;

	return 0;
}
