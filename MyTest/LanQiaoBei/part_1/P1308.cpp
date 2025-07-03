#include <bits/stdc++.h>
#define il inline
#define rg register
using namespace std;

il void strtolower(string& str)
{
	for (int i = 0, len = str.size(); i < len; i++)
		str[i]=tolower(str[i]);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	rg string word, context, part;cin >> word;
	strtolower(word);	//单词变小写
	cin.ignore();
	getline(cin, context);
	strtolower(context);	//文本变小写

	rg int many = 0, first = -1;
	
	int found = context.find(word, 0);
	while (found != string::npos)
	{
		if (found == 0 || (context[found - 1] == ' ' && context[found + word.size()] == ' '))
		{
			many++;
			if (first == -1) first = found;
		}
		found = context.find(word, found+1);
	}

	if (many)
		cout << many << " " << first << "\n";
	else
		cout << first << "\n";
	return 0;
}