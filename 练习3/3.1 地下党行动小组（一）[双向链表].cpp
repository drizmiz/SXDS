// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>     // 输入输出流头文件
#include <algorithm>    // 算法库
//#include <list>		// 链表
#include <vector>	// 顺序存储的顺序表
#include <map>		
#include <functional>
#include <memory>
#include <string>

using namespace std;

template <typename T>
class mlist
{
public:
	struct node;
	using node_p = shared_ptr<node>;

	struct node
	{
		T data;
		node_p next;
		node_p prev;
	};

	node_p first = nullptr;
	node_p last = nullptr;

	void insert_after(node_p nodep, T&& data)
	{
		node_p newnode = make_shared<node>();
		newnode->data = move(data);
		newnode->prev = nodep;
		newnode->next = nodep->next;
		if (nodep->next)
		{
			nodep->next->prev = newnode;
		}
		else
		{
			last = newnode;
		}
		nodep->next = newnode;
	}

	void insert_last(T&& data)
	{
		if (last)
			insert_after(last, move(data));
		else
		{
			node_p newnode = make_shared<node>();
			newnode->data = move(data);
			newnode->next = newnode->prev = nullptr;
			first = last = newnode;
		}
	}

	node_p find(const T& needle)
	{
		for (node_p it = first; it; it = it->next)
		{
			if (it->data == needle)
				return it;
		}
		return nullptr;
	}
};

struct member
{
	string call;
	int id = 0;
	bool operator==(const member& rhs) const
	{
		return call == rhs.call;
	}
};

int main()
{
	mlist<member> A, B;
	int numA = 0, numB = 0;
	cin >> numA >> numB;
	for (size_t i = 0; i < numA; i++)
	{
		member m;
		cin >> m.call >> m.id;
		A.insert_last(move(m));
	}
	for (size_t i = 0; i < numB; i++)
	{
		member m;
		cin >> m.call >> m.id;
		B.insert_last(move(m));
	}
	char c = '\0';
	cin >> c;
	member needle;
	cin >> needle.call;
	needle.id = 0;
	mlist<member>::node_p np = nullptr;
	if (c == 'A')
	{
		np = A.find(needle);
	}
	else if (c == 'B')
	{
		np = B.find(needle);
	}
	if (np && np->next)
		cout << np->next->data.call << ' ' << np->next->data.id;
	else
		cout << "没有人";
	cout << endl;
}
