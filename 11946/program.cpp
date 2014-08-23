#include <iostream>
#include <string>
#include <fstream>

using namespace std;

char symb[] = "OIZEASGTBP";

int main()
{
	int test;
	ifstream infile;
	infile.open("./sample.txt");

	infile >> test;
	infile.ignore();
	
	string lstr;
	while( getline(infile, lstr) )
	{
		int len = lstr.size();
		for( int i = 0; i < len; ++i)
		{
			if( isdigit(lstr[i]) )
				cout << symb[lstr[i]-'0'];	
			else
				cout << lstr[i];
		}
		cout << endl;
	}
		
	return 0;
}
