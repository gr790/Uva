#include <iostream>
#include <string>
#include <set>
#include <fstream>

using namespace std;

bool is_palim(string &s)
{
	int len = s.size();
	if(len < 2 )
		return true;
	for(int i = 0; i < len; ++i)
	{
		if( s[i] != s[len-i-1])
			return false;
	}

	return true;
}

int main()
{
	ifstream infile;
	infile.open("./sample.txt");
	
	int test;
	string str;
	infile >> test;
	infile.ignore();

	while(test--)
	{
		set<string> sub;
		infile >> str;
		int len = str.size();
		for(int i = 0; i < len; ++i)
		{
			for(int j = 0; j < len; ++j)
			{
				sub.insert(str.substr(i, len-j));
			}
		}

		set<string>::iterator it;
		int max = 0;
		for(it = sub.begin(); it != sub.end(); ++it)
		{
			//cout << *it << endl;
			string s(*it);
			if(is_palim(s))
			{
				int len = s.size();
				if( len > max )	
					max = len;
				
			}
		}

		cout << max << endl;
		sub.clear();
		str.clear();
	}

	return 0;
}
