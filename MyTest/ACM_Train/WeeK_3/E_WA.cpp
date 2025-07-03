#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1;
	while (getline(cin, s1))
	{
		set<string> a;
		int len = count(s1.begin(), s1.end(), ' ') + 1;  //错误在这里
		istringstream cins(s1);
		string word;
		for (int i = 0; i < len; i++)				//其不能准确对输入流进行正确处理，可能导致输入不完整  (例子待补充)
		{
			cins >> word;
			if (word[0] == '#')
			{
				if(a.size() != 0)
					cout << a.size() << endl;
				goto over;
			}
			else if (word[word.size() - 1] == '#')
			{
				a.insert(word);
				cout << a.size() << endl;
				goto over;
			}
			a.insert(word);
		}
		cout << a.size() << endl;
	}
over:
	return 0;
}