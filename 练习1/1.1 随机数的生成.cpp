// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>     // 输入输出流头文件
#include <cmath>        // rand所在头文件

using namespace std;

int main()
{
    int n, a, b;
    srand(0);   // 设置随机种子
    cin >> n >> a >> b;
    for (size_t i = 0; i < n; i++)
    {
        if (i)
            cout << ' ';
        // 调用rand()获得一随机整数，再取余
        cout << (rand() % (b - a) + a);
    }
    return 0;
}
