// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>     // 输入输出流头文件
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

const string en_digit = "zero, one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen, twenty";
const string en_modten = "xxx0, xxx1, twenty, thirty, forty, fifty, sixty, seventy, eighty, ninety";

vector<string> ed_map;
vector<string> em_map;

vector<string> split(const string& str, const regex& delim)
{
	vector<string> ret(
		sregex_token_iterator(str.begin(), str.end(),
			delim, -1),
		sregex_token_iterator()
	);
	return move(ret);
}

void initializer()
{
	ed_map = split(en_digit, regex(",\\s+"));
	em_map = split(en_modten, regex(",\\s+"));
}

int en_to_lower20(const string& en)
{
	return find(ed_map.begin(), ed_map.end(), en) - ed_map.begin();
}

int en_to_mod10(const string& en)
{
	return (find(em_map.begin(), em_map.end(), en) - em_map.begin()) * 10;
}

int en_to_lower100(const vector<string>& en)
{
	if (en.size() == 2)
		return en_to_mod10(en[0]) + en_to_lower20(en[1]);
	if (en.size() == 1)
	{
		int tmp = en_to_lower20(en[0]);
		if (tmp > 20)
			return en_to_mod10(en[0]);
		else
			return tmp;
	}
	return -1;
}

int extract(const vector<string>& words)
{
	for (size_t i = 0; i < words.size(); ++i)
		if (words[i] == "million")
		{
			vector<string> f(i), b(words.size() - i - 1);
			copy(words.begin(), words.begin() + i, f.begin());
			copy(words.begin() + i + 1, words.end(), b.begin());
			return extract(f) * 1000000 + extract(b);
		}
	for (size_t i = 0; i < words.size(); ++i)
		if (words[i] == "thousand")
		{
			vector<string> f(i), b(words.size() - i - 1);
			copy(words.begin(), words.begin() + i, f.begin());
			copy(words.begin() + i + 1, words.end(), b.begin());
			return extract(f) * 1000 + extract(b);
		}
	int ret = 0;
	vector<string> b = words;
	for (size_t i = 0; i < words.size(); ++i)
		if (words[i] == "hundred")
		{
			b.clear();
			b.resize(words.size() - i - 1);
			copy(words.begin() + i + 1, words.end(), b.begin());
			ret += en_to_lower20(words[i - 1]) * 100;
			break;
		}
	return ret += en_to_lower100(b);
}

int decode(const string& s)
{
	auto words = split(s, regex("\\s+"));

	int sign = 1;
	if (words[0] == "negative")
	{
		sign = -1;
		words.erase(words.begin());
	}

	int ret = extract(words);
	return ret * sign;
}

int main()
{
	initializer();

	for (;;)
	{
		string s;
		getline(cin, s);
		if (s == "")break;
		cout << decode(s) << endl;
	}
}
