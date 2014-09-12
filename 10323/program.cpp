#include <iostream>
#include <fstream>
#include <limits.h>

using namespace std;
typedef long long int ll_int;
ll_int table[20] = {0};

void fact()
{
	table[0] = 1;	
	for(int i = 1; i < 14; ++i)
		table[i] = i * table[i-1];
}

int main()
{
	ifstream infile;
	infile.open("./sample.txt");
	int n;
	fact();

	while( infile >> n )
	{
		if ( n < 0 )
		{
			if((n%2) == 0) 
				cout <<"Underflow!"<< endl; 
			else
				cout <<"Overflow!"<< endl; 
		}
		else if ( n > 13 )
			cout <<"Overflow!"<< endl; 
		else if ( n < 8)
			cout <<"Underflow!"<< endl; 
		else 
			cout << table[n] << endl;
	}
	return 0;
}
