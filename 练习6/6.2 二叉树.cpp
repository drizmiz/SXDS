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

int f(int x, int y)
{
	if (x == y)
		return x;
	else if (x > y)
		return f(x / 2, y);
	else
		return f(x, y / 2);
}

int main()
{
	int x, y;
	cin >> x >> y;
	cout << f(x, y) << endl;
}
