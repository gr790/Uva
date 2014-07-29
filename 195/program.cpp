#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

bool valueComp(const string &lhs, const string &rhs)
{
       	for (string::const_iterator c1 = lhs.begin(), c2 = rhs.begin();
               	 (c1 != lhs.end() && c2 != rhs.end());  ++c1, ++c2)
        {
		char ch1 = toupper(*c1);
		char ch2 = toupper(*c2);
		if( ch1 != ch2 )
		{
			return ch1 < ch2 ? 1 : 0;
		}
		else if ( ch1 == ch2 )
		{
			if(isupper(*c1) && !isupper(*c2))
				return 1;
			else if( isupper(*c2) && !isupper(*c1))
				return 0;
				
		}
       	}
	return true;

}

int main()
{
	ifstream infile;
	infile.open("./sample.txt");
	int test;
	infile >> test;
	infile.ignore();
	while(test--)
	{
		string word;
		infile >> word;
		sort(word.begin(), word.end());
		vector<string> sub;

		do
		{
			sub.push_back(word);
		}while( next_permutation(word.begin(), word.end()));


		sort(sub.begin(), sub.end(), valueComp);

		vector<string>::iterator it;
		for(it = sub.begin(); it != sub.end(); ++it)
			cout << *it << endl;
		word.clear();
		sub.clear();
	}

	return 0;
}
