
// main

#include <iostream>
#include <fstream>

#include <vector>

#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<vector<int> > data(N);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < i + 1; ++j)
		{
			int t;
			cin >> t;
			data[i].push_back(t);
		}

	for (int i = N - 2; i >= 0; --i)
		for (int j = 0; j < i + 1; ++j)
			data[i][j] += max(data[i + 1][j], data[i + 1][j + 1]);

	cout << data[0][0] << endl;
}