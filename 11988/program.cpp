#include <iostream>
#include <string>
#include <fstream>
#include <list>
using namespace std;

int main()
{
  freopen("./sample.txt", "r", stdin);

	string str;
	while(  getline(cin, str))
	{
		int len = str.size();
		list<char> clist;
		list<char>::iterator it;
		it = clist.begin();
		for(int i = 0; i < len; ++i)
		{
			if(str[i] == '[' )
				it = clist.begin();
			else if(str[i] == ']')
				it = clist.end();
			else
				clist.insert(it, str[i]); 
		}
		for(it = clist.begin(); it != clist.end(); ++it)
			cout << *it;
		cout << endl;
	}
	return 0;
}
