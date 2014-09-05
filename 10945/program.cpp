#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define R(x)	((x >= 'A' && x <= 'Z') ? x + 32 : x)

#define C(x)	( (x >= 'A' && x <= 'Z') ? x : (x >= 'a' && x <= 'z') ? x : 0 )

void compress(string &s, int &j)
{
	int len = s.size();
	j = 0;
	for(int i = 0; i < len; ++i)
	{
		if( isalpha(s[i]) )
			s[j++] = s[i];
	}
  s.resize(j);
}

bool is_palim(string &s)
{
	int len = s.size();
	if( len < 2 )
		return true;

	compress(s, len);
	for(int i = 0; i < len/2; ++i)
	{
		if( isalpha(s[i]) && isalpha(s[len-i-1]) )
			if(R(s[i]) != R(s[len-i-1]))
				return false;
	}	

	return true;
}

int main()
{
	ifstream infile;
	infile.open("./sample.txt");
	string lstr;

	while( getline(infile, lstr))
	{
		if( lstr == "DONE")
			break;

		if(is_palim(lstr))
			cout <<"You won't be eaten!" << endl;
		else
			cout <<"Uh oh.." << endl;

		lstr.clear();
	}
	
	return 0;

}
