
// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include <string>
#include <vector>

#include <algorithm>
#include <type_traits>

#include <cassert>

using namespace std;

class str_view
{
private:
	const char* ptr;
	size_t len;
public:
	str_view(const char* cc, size_t sz)
		: ptr(cc), len(sz) 
	{ }
	str_view(const char* cc)
		: ptr(cc), len(char_traits<char>::length(cc))
	{ }
	char operator[](size_t idx) {
		assert(idx < len);
		return ptr[idx];
	}
	char at(size_t idx) {
		return operator[](idx);
	}
	size_t size() const { return len; }
	bool empty() const { return !size(); }
	str_view substr(size_t pos, size_t count) const
	{
		auto rcount = min(count, size() - pos);
		return str_view(ptr + pos, rcount);
	}
};

const int nul = -1;

struct node
{
	int parent = nul;
	int lchild = nul;
	int rsibling = nul;
};

vector<node> space;

void gen(str_view dfs_seq, int ini = 0)
{
	if (dfs_seq.empty())
		return;
	if (dfs_seq[0] == 'd')
	{
		node newnode;
		newnode.parent = ini;
		space.push_back(newnode);
		const int newnode_idx = space.size() - 1;

		if (space[ini].lchild == nul)
		{
			space[ini].lchild = newnode_idx;
		}
		else
		{
			int idx = space[ini].lchild;
			for (; space[idx].rsibling != nul;)
				idx = space[idx].rsibling;
			space[idx].rsibling = newnode_idx;
		}
		gen(dfs_seq.substr(1, dfs_seq.size() - 1), newnode_idx);
	}
	else
	{
		gen(dfs_seq.substr(1, dfs_seq.size() - 1), space[ini].parent);
	}
}

int height(int ini = 0)
{
	if (ini == nul)
		return -1;
	int ret = 0;
	ret = max(
		height(space[ini].lchild),
		height(space[ini].rsibling)
	) + 1;
	return ret;
}

int main()
{
	int i = 0;
	for (; ++i;)
	{
		string seq;
		cin >> seq;
		if (seq == "#")
			break;
		int h1 = 0, h1t = 0;
		for (auto c : seq)
		{
			if (c == 'd')
				h1t++;
			else
				h1t--;
			h1 = max(h1, h1t);
		}
		space.clear();
		node root;
		space.push_back(root);
		gen(str_view(seq.c_str()));
		cout << "Tree " << i << ": " << h1
			<< " => " << height() << endl;
	}
}
