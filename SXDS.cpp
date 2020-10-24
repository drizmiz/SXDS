// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>     // 输入输出流头文件
#include <algorithm>    // 算法库
//#include <list>		// 链表
#include <iomanip>		// i/o manipulate
#include <memory>

using namespace std;

template <typename T>
class mforward_list
{
public:
	struct node;
	using node_p = shared_ptr<node>;

	struct node
	{
		T data;
		node_p next;
	};
private:
	size_t _size = 0;

	node_p before_first = nullptr;
	//node_p last = nullptr;
public:
	size_t size() const { return _size; }
	node_p before_begin() const { return before_first; }
	node_p begin() const { return before_first->next; }

	mforward_list() {
		node_p head = make_shared<node>();
		//head->data is undefined
		head->next = nullptr;
		before_first = head;
	}

	// insert after
	node_p insert(node_p nodep, T&& data)
	{
		node_p newnode = make_shared<node>();
		newnode->data = move(data);
		newnode->next = nodep->next;
		nodep->next = newnode;
		++_size;
		return newnode;
	}

	void push_front(T&& data)
	{
		insert(before_first, move(data));
	}

	node_p find(const T& needle) const
	{
		for (node_p it = begin(); it ; it = it->next)
		{
			if (it->data == needle)
				return it;
		}
		return nullptr;
	}

	template<class Pr>
	node_p find_if(const T& needle, node_p start, Pr pred)
	{
		for (; start; start = start->next)
			if (pred(start->data))
				return start;
		return nullptr;
	}
};

struct location
{
	string name;
	double x = 0.0, y = 0.0;
	bool operator==(const location& rhs) const
	{
		return name == rhs.name;
	}
	double distance(const location& rhs) const
	{
		return sqrt(pow(rhs.x - x, 2) + pow(rhs.y - y, 2));
	}
};

int main()
{
	size_t spotnum;
	cin >> spotnum;
	mforward_list<location> locs;
	auto p = locs.before_begin();
	for (size_t i = 0; i < spotnum; i++)
	{
		location loc;
		cin >> loc.name >> loc.x >> loc.y;
		p = locs.insert(p, move(loc));
	}
	size_t PDnum;
	cin >> PDnum;
	for (size_t i = 0; i < PDnum; i++)
	{
		location needle;
		cin >> needle.x >> needle.y;

		double dist = 0.0;
		cin >> dist;

		bool first = true;
		for (auto it = locs.begin(); it; )
		{
			auto found = locs.find_if(needle, it,
				[&](const location& loc) {
					return needle.distance(loc) <= dist;
				}
			);
			if (!found)
				break;

			if (!first)
				cout << ' ';
			else
				first = false;
			cout << found->data.name;

			it = found->next;
		}

		if (first)
			cout << "未找到地点";
		cout << endl;
	}
}
