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
#include <cassert>

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
private:
	size_t _size = 0;

	node_p first = nullptr;
	node_p last = nullptr;
public:
	size_t size() const { return _size; }
	node_p begin() const { return first; }
	node_p before_end() const { return last; }

	// insert after
	void insert(node_p nodep, T&& data)
	{
		node_p newnode = make_shared<node>();
		newnode->data = move(data);
		newnode->prev = nodep;
		newnode->next = nodep->next;
		if (nodep->next) // 不是尾结点
		{
			nodep->next->prev = newnode;
		}
		else
		{
			last = newnode;
		}
		nodep->next = newnode;
		++_size;
	}

	void push_back(T&& data)
	{
		if (size())
			insert(last, move(data));
		else
		{
			node_p newnode = make_shared<node>();
			newnode->data = move(data);
			newnode->next = newnode->prev = nullptr;
			first = last = newnode;
			++_size;
		}
	}

	node_p find(const T& needle) const
	{
		for (node_p it = first; it; it = it->next)
		{
			if (it->data == needle)
				return it;
		}
		return nullptr;
	}

	void erase(node_p nodep)
	{
		if (nodep->prev)
			nodep->prev->next = nodep->next;
		else
			first = nodep->next;
		if (nodep->next)
			nodep->next->prev = nodep->prev;
		else
			last = nodep->prev;
		//assert(nodep.use_count() == 0);
		--_size;
	}
};

template<typename T>
ostream& operator<<(ostream& out, const mlist<T>& A)
{
	bool flag = false;
	for (auto p = A.begin(); p; p = p->next)
	{
		if (p != A.begin())
			out << " ";
		out << p->data.call;
		flag = true;
	}
	if (!flag)
		out << "全军覆没";
	return out;
}

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
		A.push_back(move(m));
	}
	for (size_t i = 0; i < numB; i++)
	{
		member m;
		cin >> m.call >> m.id;
		B.push_back(move(m));
	}
	int n;
	cin >> n;
	for (; n--;)
	{
		char c = '\0';
		cin >> c;
		member needle;
		cin >> needle.call;
		needle.id = 0;
		mlist<member>::node_p np = nullptr;
		if (c == 'A')
		{
			np = A.find(needle);
			if (np)
				A.erase(np);
		}
		else if (c == 'B')
		{
			np = B.find(needle);
			if (np)
				B.erase(np);
		}
	}
	cout << A << endl;
	cout << B << endl;
}
