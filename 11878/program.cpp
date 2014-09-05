#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int main()
{
	string lstr;
	stringstream ss;
	int count = 0;

	while( getline( cin, lstr) )
	{
		int a, b, output;
		char symb1, symb2;

		ss.str(lstr);

		ss >> a ;
		ss >> symb1;
		ss >> b;
		ss >> symb2;
		ss >> output;

		if( symb1 == '+')
		{
			if( a + b == output )
				count++;
		}
		else if ( symb1 == '-')
		{
			if( a - b == output)
				count++;
		}

		ss.clear();
		lstr.clear();
		
	}
	cout << count << endl;

	return 0;
}
