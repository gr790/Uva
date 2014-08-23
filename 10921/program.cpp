#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define R(x)	((x >= 'A' && x <= 'Z') ? 1 : 0)

void solve( string &s)
{
	int len = s.size();
	for(int i = 0; i < len; ++i )
	{
		if( R(s[i]) )
		{
			switch (s[i]) 
			{
				case 'A':
				case 'B':
				case 'C':
					s[i] = '0' + 2;
					break;
				case 'D':
				case 'E':
				case 'F':
					s[i] = '0' + 3;
					break;
				case 'G':
				case 'H':
				case 'I':
					s[i] = '0' + 4;
					break;
				case 'J':
				case 'K':
				case 'L':
					s[i] = '0' + 5;
					break;
				case 'M':
				case 'N':
				case 'O':
					s[i] = '0' + 6;
					break;
				case 'P':
				case 'Q':
				case 'R':
				case 'S':
					s[i] = '0' + 7;
					break;
				case 'T':
				case 'U':
				case 'V':
					s[i] = '0' + 8;
					break;
				case 'W':
				case 'X':
				case 'Y':
				case 'Z':
					s[i] = '0' + 9;
					break;
			}		
		}
	}
	cout << s << endl;
}

int main()
{
	string lstr;
	ifstream infile;
	infile.open("./sample.txt");
	
	while( infile >> lstr )
	{
		solve(lstr);
		lstr.clear();
	}

	return 0;
}
