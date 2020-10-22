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

	node_p before_first = nullptr;
	node_p after_last = nullptr;
public:
	size_t size() const { return _size; }
	node_p begin() const { return before_first->next; }
	node_p end() const { return after_last; }
	node_p before_end() const { return end()->prev; }

	mlist() {
		node_p head = make_shared<node>();
		//head->data is undefined
		head->prev = nullptr;
		before_first = head;
		node_p tail = make_shared<node>();
		//tail->data is undefined
		tail->next = nullptr;
		after_last = tail;

		head->next = after_last;
		tail->prev = before_first;
	}

	// insert after
	void insert(node_p nodep, T&& data)
	{
		node_p newnode = make_shared<node>();
		newnode->data = move(data);
		newnode->prev = nodep;
		newnode->next = nodep->next;
		nodep->next->prev = newnode;
		nodep->next = newnode;
		++_size;
	}

	// assume *this is sorted
	template<class Pred>
	void insert(T&& data, Pred pred)
	{
		if (!size())
		{
			push_back(move(data));
			return;
		}

		auto t = begin();
		for (; t != end() && pred(t->data, data);)
			t = t->next;

		insert(t->prev, move(data));
	}

	void push_back(T&& data)
	{
		insert(before_end(), move(data));
	}

	node_p find(const T& needle) const
	{
		for (node_p it = begin(); it != end(); it = it->next)
		{
			if (it->data == needle)
				return it;
		}
		return nullptr;
	}

	void erase(node_p nodep)
	{
		nodep->prev->next = nodep->next;
		nodep->next->prev = nodep->prev;
		//assert(nodep.use_count() == 0);
		--_size;
	}

	void merge(const mlist<T>& rhs)
	{
		auto t = begin();
		for (auto p = rhs.begin(); p != rhs.end(); p = p->next)
		{
			insert(move(p->data), less<T>());
		}
	}
};

template<typename T>
ostream& operator<<(ostream& out, const mlist<T>& A)
{
	for (auto p = A.begin(); p != A.end(); p = p->next)
	{
		out << p->data.call << ' ' << p->data.id << endl;
	}
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
	bool operator<(const member& rhs) const
	{
		return id < rhs.id;
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
	A.merge(B);
	int n;
	cin >> n;
	for (; n--;)
	{
		member freshman;
		cin >> freshman.call >> freshman.id;
		A.insert(move(freshman), less<member>());
	}
	cout << A;
}
