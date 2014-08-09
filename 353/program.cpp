#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <set>

using namespace std;

bool is_palim(string &s)
{
	int len = s.size();
	if ( len < 2)
		return true;
	for(int i = 0; i < (int)len/2; ++i)
	{
		if( s[i] != s[len-i-1])
			return false;
	}

	return true;
}

void compress(string &s, int &l)
{
	int len = s.size();
	l = 0;
	for(int i = 0; i < len; ++i)
	{
		if(s[i] != ' ')
			s[l++] = s[i];
	}
}

int main()
{
        ifstream infile;
        infile.open("./sample.txt");

        string str;
        set<string> sub;
        while( infile >> str )
        {
		int len = 0;
		compress(str, len);
                for(int i = 0; i < len; ++i )
                {
                        for(int j = 0; j < len; ++j)
                        {
                                sub.insert(str.substr(i, len-j));
                        }
                }

        	set<string>::iterator it;
		int cnt = 0;
	        for(it = sub.begin(); it != sub.end(); ++it)
        	{
                //	cout << *it << endl;
			string s(*it);
			if(is_palim(s))
				cnt++;
        	}
		cout <<"The string '"<< str <<"' contains "<< cnt <<" palindromes." << endl;
		sub.clear();
	}

        return 0;
}

