// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>     // ���������ͷ�ļ�
#include <algorithm>    // �㷨��
#include <vector>		// vector

using namespace std;

int main()
{
	int c = 0;
	cin >> c;
	for (size_t _i = 0; _i < c; _i++)
	{
		int n, x, y;
		cin >> n >> x >> y;

		vector<int> input(n);
		for (size_t i = 0; i < n; i++)
			cin >> input[i];

		reverse(input.begin(), input.end());

		for (size_t i = 0; i < n; i++)
			if (input[i] > x&& input[i] < y)
			{
				cout << input[i - 1] << ' '
					<< input[i + 1] << endl;
				break;
			}
	}
}
