#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;


bool is_vowel(char c)
{
	if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' )
		return true;
	return false;
}

int main()
{
	ifstream infile;
	infile.open("./sample.txt");

	int test;
	infile >> test;
	infile.ignore();

	string orig, fake;
	multimap<char, int> ind;

	while(test--)
	{
		infile >> orig;
		infile >> fake;
		bool found = true;

		if( orig.size() != fake.size() )
			found = false;
		else
		{
			int len = orig.size();
			for(int i = 0; i < len; ++i)
			{
				if(is_vowel(orig[i]) )
				{
					if( !is_vowel(fake[i]))
					{
						found = false;
						break;
					}
				}
				else
				{
					if( orig[i] != fake[i])
					{
						found = false;
						break;
					}
				}
			}
		}
		if(!found)
			cout <<"No" << endl;
		else
			cout <<"Yes" << endl;

		orig.clear();
		fake.clear();
	}

	return 0;
}
