// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

struct node
{
	int l = -1, r = -1;
};

vector<node> vec;

int depth(int idx)
{
	int mx = 1;
	if (vec[idx].l != -1)
		mx = max(mx, depth(vec[idx].l) + 1);
	if (vec[idx].r != -1)
		mx = max(mx, depth(vec[idx].r) + 1);
	return mx;
}

int main()
{
	int n;
	cin >> n;
	vec.resize(n + 1);
	for (int _i = 1; _i <= n; ++_i)
	{
		int i, j;
		cin >> i >> j;
		vec[_i].l = i;
		vec[_i].r = j;
	}
	cout << depth(1) << endl;
}
