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
	int N, M;
	cin >> N >> M;
	vector<int> vec(N);

	for (size_t i = 0; i < N; i++)
		cin >> vec[i];

	for (; M > N;)
		M -= N;

	rotate(vec.begin(), vec.begin() + N - M, vec.end());

	for (size_t i = 0; i < N; i++)
	{
		if (i)
			cout << ' ';
		cout << vec[i];
	}

	cout << endl;
	return 0;
}
