#include <iostream>
#include <limits.h>
#include <sstream>
#include <fstream>
using namespace std;

void solve( long double num1, char symb, long double num2)
{
	if( num1 > INT_MAX)
		cout <<"first number too big" << endl;

	if( num2 > INT_MAX)
		cout <<"second number too big" << endl;

	switch(symb)
	{
		case '*':
			{
				if( (num1 * num2) > INT_MAX)
					cout <<"result too big" << endl;
				break;
			}
		case '+':
			{
				if ( (num1 + num2 ) > INT_MAX)
					cout <<"result too big" << endl;
				break;
			}
		default:
			break;
	}
}
int main()
{
	string lstr;
	istringstream ss;
	ifstream infile;
	infile.open("./sample.txt");
	while ( getline(infile, lstr) )
	{
		long double num1, num2;
		num1 = num2 = 0;
		char symb = 0;
		ss.str(lstr);

		ss >> num1;
		ss >> symb;
		ss >> num2;
		cout << lstr << endl;

		solve(num1, symb, num2);
		
		ss.clear();
		lstr.clear();
		num1 = num2 = symb = 0;
	}

	return 0;
	
}
