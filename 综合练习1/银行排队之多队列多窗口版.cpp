
// 注释请见提交文件夹中的queue版本

#include <iostream>
#include <iomanip>

#include <vector>

#include <algorithm>

using namespace std;

using customer = int;

struct w
{
	int idx = 0;
	vector<customer> cus;

	size_t size()const { return cus.size(); }
	void push(customer c) { cus.push_back(c); }

	bool operator>(const w& other) const
	{
		return size() < other.size() ? true :
			(size() == other.size()
				&& idx < other.idx);
	}
	bool operator<(const w& other) const
	{
		return !operator>(other);
	}
};

int main()
{
	size_t N, K, M;
	cin >> N >> K >> M;
	vector<size_t> Ts(N), Ps(N);
	for (int ix = 0; ix < N; ++ix)
	{
		cin >> Ts[ix] >> Ps[ix];
		if (Ps[ix] > 60)
			Ps[ix] = 60;
	}

	vector<w> v(K);
	int i = 0;
	generate(v.begin(), v.end(),
		[&]() {
			w particular_w;
			particular_w.idx = i;
			++i;
			return particular_w;
		});

	int cumulate_time = 0;
	int now = 0;

	for (int ix = 0; ix < N; ++ix)
	{
		const int arrival = Ts[ix];

		int min_left = 61;

		for (auto& window : v)
		{
			int diff = arrival - now;

			auto& line = window.cus;

			int tmp = 0;
			for (auto& c : line)
			{
				cumulate_time += min(diff, tmp);
				tmp += c;
			}

			for (int j = 0; j < line.size();)
			{
				auto& c = line[j];
				if (c - diff <= 0)
				{
					diff -= c;
					line.erase(line.begin() + j);
				}
				else {
					c -= diff;
					diff = 0;
					min_left = min(min_left, c);
					break;
				}
			}
		}

		sort(v.begin(), v.end(), greater<w>());
		now = arrival;
		if (v.begin()->size() < M)
		{
			v.begin()->push(Ps[ix]);
		}
		else
		{
			for (int iy = ix; iy < N; ++iy)
				if (Ts[iy] - now < min_left)
				{
					cumulate_time += min_left -
						(Ts[iy] - now);
					Ts[iy] = now + min_left;
				}

			--ix;
		}
	}

	for (auto& window : v)
	{
		int tmp = 0;
		for (auto& c : window.cus)
		{
			cumulate_time += tmp;
			tmp += c;
		}
	}

	cout << fixed << setprecision(1) <<
		(static_cast<double>(cumulate_time) / N)
		<< endl;
	return 0;
}