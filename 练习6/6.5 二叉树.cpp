// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
#include <iomanip>
#include <sstream>

#include <string>
#include <stack>
#include <vector>
#include <deque>
#include <queue>

#include <map>
#include <unordered_map>

#include <algorithm>
#include <functional>

#include <limits>

using namespace std;

int up_bound(int m) //  ret>m
{
	int i = 0, n = 1;
	for (; n <= m; ++i) n <<= 1;
	return i;
}

int f(int m, int n)
{
	//int ret = 1;
	//if (n >= 2 * m)
	//{
	//	ret += f(2 * m, n);
	//	if (n >= 2 * m + 1)
	//		ret += f(2 * m + 1, n);
	//}
	//return ret;

	// ���������
	int cm = up_bound(m);
	int cn = up_bound(n);

	int tmp = 1 << (cn - cm);
	// ���ǳ������һ��
	int ret = tmp - 1;
	// �������һ����߽�
	int fst = m * tmp;
	// �������һ��β��
	int lst = (m + 1) * tmp;
	if (n >= fst)
		if (n >= lst - 1)
			ret += lst - fst;
		else
			ret += n - fst + 1;
	return ret;
}

int main()
{
	for (;;)
	{
		int m, n;
		cin >> m >> n;
		// m=3, n=12
		if (!m && !n)
			break;
		cout << f(m, n) << endl;
	}
}
