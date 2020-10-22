// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>     // ���������ͷ�ļ�
#include <algorithm>    // �㷨��
//#include <list>		// ����
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
		for (node_p it = begin(); it; it = it->next)
		{
			if (it->data == needle)
				return it;
		}
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
	size_t searchnum;
	cin >> searchnum;
	for (size_t i = 0; i < searchnum; i++)
	{
		location needle;
		cin >> needle.name;
		auto it = locs.find(needle);
		cout << fixed << setprecision(1);
		cout << it->data.x << ' ' << it->data.y << endl;
	}
}
