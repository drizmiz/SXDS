
// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int Calc[20][20]; // DP

int calc(size_t n)
{
	for (size_t ss = 0; ss <= n; ++ss)
		Calc[0][ss] = 1;
	for (size_t N = 1; N <= n; ++N)
	{
		Calc[N][0] = Calc[N - 1][1];
		for (size_t ss = 1; ss <= n - N; ++ss)
			Calc[N][ss] = Calc[N - 1][ss + 1] + Calc[N][ss - 1];
	}
	return Calc[n][0];
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", calc(n));
}