
// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include <string>
#include <vector>

#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& i : v)
		cin >> i;
	int aim;
	cin >> aim;
	auto res = lower_bound(v.begin(), v.end(), aim);
	if (res != v.end() && *res == aim)
		cout << res - v.begin() + 1 << endl;
	else
		cout << "no answer" << endl;
}
