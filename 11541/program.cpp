#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream infile;
	infile.open("./sample.txt");

	int test;
	infile >> test;
	infile.ignore();

	string s;
	int k = 0;
	while(k++ < test)
	{
		infile >> s;
		int len = s.size();
		char ch;
		int num = 0;
		printf("Case %d: ", k);
		bool done = false;
		int i;
		for(i = 0; i < len; ++i)
		{
			if(isalpha(s[i]))
			{
				if(!done)
				{
					int j;
					for(j = 0; j < num; ++j)
						cout << ch;
					if(j==num)
						done = false;
					ch = s[i];
					num = 0;
				}
			}
			else
			{
				num = num * 10 + (s[i] - '0');
			}
		}
		if(i == len)
		{
			int j;
			for(j = 0; j < num; ++j)
				cout << ch;
		}
		s.clear();
		cout << endl;
	}

	return 0;
}
