
// main

#include <iostream>

#include <vector>
#include <valarray>

#include <algorithm>

#include <cassert>

using namespace std;

using uint = unsigned;

// matrix

class matrix
{
private:
	valarray<int> data;
	bool _Verify(uint i, uint j) const {
		return i < row && j < col;
	}
public:
	uint row;
	uint col;
	matrix(uint M, uint N) : data(M* N), row(M), col(N) {  }		// M ÐÐ N ÁÐ
	int& operator()(uint i, uint j) {
#ifdef _DEBUG
		assert(_Verify(i, j));
#endif				// i : 0 to M-1 ; j : 0 to N-1
		return data[i * col + j];
	}
	const int& operator()(uint i, uint j) const {
#ifdef _DEBUG
		assert(_Verify(i, j));
#endif
		return data[i * col + j];
	}
};

const short err = -10000;

int main()
{
	int n, m, K;
	cin >> n >> m >> K;
	matrix data(n, m);
	matrix dp(n, m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			char c;
			do {
				c = cin.get();
			} while (isspace(c));
			switch (c)
			{
			case '#':
				data(i, j) = 0; break;
			case '*':
				data(i, j) = 1; break;
			default:
				assert(false); break;
			}
		}

	dp(n - 1, m - 1) = 0;

	for (int i = n - 2; i >= 0; --i)
		if (data(i, m - 1))
		{
			dp(i, m - 1) = dp(i + 1, m - 1) + 1;
			if (dp(i, m - 1) > K)
				dp(i, m - 1) = err;
		}
		else
			dp(i, m - 1) = dp(i + 1, m - 1);

	for (int j = m - 2; j >= 0; --j)
		if (data(n - 1, j))
		{
			dp(n - 1, j) = dp(n - 1, j + 1) + 1;
			if (dp(n - 1, j) > K)
				dp(n - 1, j) = err;
		}
		else
			dp(n - 1, j) = dp(n - 1, j + 1);

	for (int i = n - 2; i >= 0; --i)
	{
		for (int j = m - 2; j >= 0; --j)
		{
			if (data(i, j))
			{
				dp(i, j) = max(
					dp(i, j + 1),
					dp(i + 1, j)
				) + 1;
				if (dp(i, j) > K)
					dp(i, j) = err;
			}
			else
				dp(i, j) = max(
					dp(i, j + 1),
					dp(i + 1, j)
				);
		}
	}

	if (dp(0, 0) < 0)
		cout << -1 << endl;
	else
		cout << dp(0, 0) << endl;
}