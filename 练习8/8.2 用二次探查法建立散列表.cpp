
// hash

#include <iostream>
#include <sstream>

#include <vector>

#include <limits>

using namespace std;

int mhash(int key, int M)
{
	return key % M;
}

const int int_max = numeric_limits<int>::max();

class inc_seq
{
private:
	int idx = 0;
public:
	int operator()()
	{
		++idx;
		if (idx % 2 == 1)
			return (idx + 1) * (idx + 1) / 4;
		else
			return -idx * idx / 4;
	}
};

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> table(M, int_max);
	stringstream ss;
	for (int i = 0; i < N; ++i)
	{
		int key;
		cin >> key;
		int idx = mhash(key, M);
		inc_seq seq;
		for (; table[idx] != int_max &&
			table[idx] != key; idx %= M)
			idx = mhash(key, M) + seq();
		table[idx] = key;
		ss << idx << " ";
	}
	auto str = ss.str();
	str = str.substr(0, str.size() - 1);
	cout << str << endl;
}