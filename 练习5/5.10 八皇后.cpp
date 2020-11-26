
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

#include <algorithm>
#include <functional>

#include <limits>

using namespace std;

string result(8, '0');
vector<int> solutions;

bool has_collision(int line1, int col1, int line2, int col2)
{
	if (col1 == col2 || line1 - col1 == line2 - col2 ||
		line1 + col1 == line2 + col2)
		return true;
	else
		return false;
}

bool has_collision(const string& prev, int line2, int col2)
{
	for (int line = 0; line < line2; ++line)
		if (has_collision(line, prev[line] - '1',
			line2, col2))
			return true;
	return false;
}

void eight_queens(int queen_id = 0)
{
	if (queen_id == 8)
	{
		solutions.push_back(stoi(result));
		return;
	}
	for (int col = 0; col < 8; ++col)
	{
		if (!has_collision(result, queen_id, col))
		{
			result[queen_id] = '1' + col;
			eight_queens(queen_id + 1);
		}
	}
}

int main()
{
	eight_queens();
	int n = 0;
	cin >> n;
	for (; n--;)
	{
		int b = 0;
		cin >> b;
		cout << solutions[b - 1] << endl;
	}
}