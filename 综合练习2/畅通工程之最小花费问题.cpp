
// main

#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

using uint = unsigned;

struct edge
{
	int from;
	int to;
	int cost;
	edge() :from(0), to(0), cost(0) {}
	edge(int x, int y, int c) :from(x), to(y), cost(c) {}
	bool operator<(const edge& rhs)
	{
		return cost < rhs.cost;
	}
};

// union_find algorithm with path compression
class union_find
{
private:
	size_t n_size;

	vector<int> root;
public:
	union_find(size_t n) :n_size(n), root(n)
	{
		for (int i = 0; i < n; i++)
			root[i] = i;
	}
	uint nsize()const { return n_size; }

	int find(int p)
	{
		if (root[p] == p)
			return p;
		else
			return root[p] = find(root[p]);
	}
	void link_root(int rx, int ry)
	{
		root[rx] = ry;
	}
	void link(int x, int y)
	{
		int rx = find(x), ry = find(y);
		if (rx != ry)
			link_root(rx, ry);
	}
};

int main()
{
	int N;
	cin >> N;

	vector<edge> roads;
	union_find uf(N);
	for (int i = 0; i < N * (N - 1) / 2; ++i)
	{
		int from, to, cost, has_built;
		cin >> from >> to >> cost >> has_built;

		// this operation maps ints from 1 to N to ints from 0 to N - 1
		--from; --to;

		edge w(from, to, has_built ? 0 : cost);
		roads.push_back(w);

		// towns with a built road are in a connected component 
		if (has_built)
			uf.link(from, to);
	}

	sort(roads.begin(), roads.end());

	int acc = 0;
	// use Kruskal algorithm to construct a MST
	for (auto& road : roads)
	{
		int root_f = uf.find(road.from);
		int root_t = uf.find(road.to);
		if (root_f != root_t)
		{
			uf.link_root(root_f, root_t);
			acc += road.cost;
		}
	}

	cout << acc << endl;
}