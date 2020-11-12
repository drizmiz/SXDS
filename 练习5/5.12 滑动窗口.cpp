
// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <iomanip>
#include <sstream>

#include <string>
#include <stack>
#include <vector>
#include <deque>

#include <algorithm>
#include <functional>

#include <limits>

using namespace std;

int main()
{
	size_t n, k;
	cin >> n >> k;
	vector<int> nums(n);
	vector<int> mi(n - k + 1), ma(n - k + 1);

	for (auto& m : nums)
		cin >> m;

	deque<int> dq_dec, dq_inc;

	for (size_t i = 0; i < n; i++)
	{
		for (;
			!dq_dec.empty() && nums[dq_dec.back()] < nums[i];
			dq_dec.pop_back()
			);

		dq_dec.push_back(i);

		if (dq_dec.front() == i - k)
			dq_dec.pop_front();

		if (i >= k - 1)
			ma[i - k + 1] = nums[dq_dec.front()];
	}

	for (size_t i = 0; i < n; i++)
	{
		for (;
			!dq_inc.empty() && nums[dq_inc.back()] > nums[i];
			dq_inc.pop_back()
			);

		dq_inc.push_back(i);

		if (dq_inc.front() == i - k)
			dq_inc.pop_front();

		if (i >= k - 1)
			mi[i - k + 1] = nums[dq_inc.front()];
	}

	bool first = true;
	for (auto& m : mi)
		if (first)
		{
			cout << m;
			first = false;
		}
		else
			cout << ' ' << m;
	cout << endl;

	first = true;
	for (auto& m : ma)
		if (first)
		{
			cout << m;
			first = false;
		}
		else
			cout << ' ' << m;
	cout << endl;
}