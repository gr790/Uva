#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	ifstream infile;
	infile.open("./sample.txt");

	int k = 0;
	string lstr;
	while( infile >> lstr)
	{
		if( lstr == "*")
			break;
		k++;
		if( lstr == "Hajj")
		{
			lstr = "Hajj-e-Akbar";
		}
		else if ( lstr == "Umrah")
		{
			lstr = "Hajj-e-Asghar";
		}
		cout <<"Case " << k <<':'<<" "<< lstr << endl;
		lstr.clear();
	}

	return 0;
}
