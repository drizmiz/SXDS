// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>     // ���������ͷ�ļ�
#include <cmath>        // rand����ͷ�ļ�

using namespace std;

int main()
{
    int n, a, b;
    srand(0);   // �����������
    cin >> n >> a >> b;
    for (size_t i = 0; i < n; i++)
    {
        if (i)
            cout << ' ';
        // ����rand()���һ�����������ȡ��
        cout << (rand() % (b - a) + a);
    }
    return 0;
}
