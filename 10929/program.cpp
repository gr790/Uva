#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
	string lstr;
	ifstream infile;
	infile.open("./sample.txt");

	while( infile >> lstr )
	{
		if( lstr == "0")
			break;

		int len = lstr.size();
		unsigned long int o_sum, e_sum;
		o_sum = e_sum = 0;
		for(int i = 0; i < len; ++i)
		{
			if(i%2 == 0)
				o_sum += (lstr[i] - '0');
			else
				e_sum += (lstr[i] - '0');
		}

		unsigned long int val = labs(o_sum - e_sum);

		if( val%11 == 0)  
			cout << lstr <<" is a multiple of 11." << endl;
		else
			cout << lstr <<" is not a multiple of 11." << endl;

		lstr.clear();
	}

	return 0;
}
