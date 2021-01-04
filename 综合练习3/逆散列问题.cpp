
// main

#include <iostream>

#include <vector>
#include <queue>

#include <algorithm>

using namespace std;

using uint = unsigned;

int N;

int linear_hash(int x)
{
	return x % N;
}

class graph
{
private:
	// adjacent table
	vector<vector<int>> adj_of_points;

	// e_size is useless here
	size_t n_size, e_size;

	vector<int> in_degree;
public:
	graph(size_t n) :n_size(n), adj_of_points(n),
		in_degree(n), e_size(0) { }
	uint nsize()const { return n_size; }
	uint esize()const { return e_size; }
	void link(int x, int y, int weight = 0)
	{
		adj_of_points[x].push_back(y);
		e_size++;
	}
	void find_indeg()
	{
		for (const auto& p : adj_of_points)
			for (const auto& adj : p)
				++in_degree[adj];
	}
	template<class Pr>
	vector<int> topo_sort(Pr P);
};

// Pr is the predicate for comparison
template<class Pr>
vector<int> graph::topo_sort(Pr P)
{
	// suppose in_deg has been obtained
	vector<int> result;

	// deg0 are the nodes with a degree of 0
	vector<int> deg0;
	for (int i = 0; i < nsize(); ++i)
		if (in_degree[i] == 0)
			deg0.push_back(i);

	priority_queue<int, vector<int>, Pr> ini(P, move(deg0));
	for (; !ini.empty();)
	{
		auto t = ini.top();
		result.push_back(t);
		ini.pop();

		for (auto& adj : adj_of_points[t])
		{
			--in_degree[adj];
			if (in_degree[adj] == 0)
				ini.push(adj);
		}
	}

	return result;
}

int main()
{
	cin >> N;
	vector<int> vec(N);

	// Nn maps ints from 0 to N to ints from 0 to n
	// nN is the opposite of Nn
	// we need this transition because the graph itself is naive		
	vector<int> Nn(N), nN;

	int j = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> vec[i];
		if (vec[i] >= 0)
		{
			Nn[i] = j;
			nN.push_back(i);
			++j;
		}
	}
	int n = nN.size();

	// to construct the graph
	graph g(n);
	for (int i = 0; i < N; ++i)
	{
		if (vec[i] < 0)
			continue;

		int base = linear_hash(vec[i]);
		for (int j = base; j != i; )
		{
			g.link(Nn[j], Nn[i]);
			++j;
			j %= N;
		}
	}

	g.find_indeg();

	auto topo = g.topo_sort(
		// the predicate first maps the nodes to their actual places,
		// secondly maps them to the corresponding numbers
		// and lastly does the comparison
		[=](const int& lhs, const int& rhs) {
			return vec[nN[lhs]] > vec[nN[rhs]];
		}
	);
	for (int i = 0; i < topo.size(); ++i)
	{
		if (i)
			cout << " ";
		cout << vec[nN[topo[i]]];
	}
}