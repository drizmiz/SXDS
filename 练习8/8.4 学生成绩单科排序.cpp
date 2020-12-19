
// hash

#include <iostream>
#include <fstream>

#include <vector>

#include <algorithm>

using namespace std;

struct record
{
	int id;
	string name;
	int score;
};

int main()
{
	ios_base::sync_with_stdio(false);
	int N, C;
	cin >> N >> C;
	vector<record> recs(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> recs[i].id >> recs[i].name
			>> recs[i].score;
	}
	switch (C)
	{
	case 1:
		sort(recs.begin(), recs.end(),
			[](const record& lhs, const record& rhs)
			{
				return lhs.id < rhs.id;
			}
		); break;
	case 2:
		sort(recs.begin(), recs.end(),
			[](const record& lhs, const record& rhs)
			{
				return lhs.name < rhs.name ||
					(lhs.name == rhs.name &&
						lhs.id < rhs.id);
			}
		); break;
	case 3:
		sort(recs.begin(), recs.end(),
			[](const record& lhs, const record& rhs)
			{
				return lhs.score > rhs.score ||
					(lhs.score == rhs.score &&
						lhs.id < rhs.id);
			}
		); break;
	default:
		break;
	}
	for (auto& r : recs)
	{
		cout.fill('0');
		cout.width(6);
		cout << r.id;
		cout << ' ' << r.name << ' '
			<< r.score << '\n';
		// endl will cause TLE
	}
}