#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	long long int n;
	ifstream infile;
	infile.open("./sample.txt");

	while( infile >> n )
	{
		if(n < 0)
			break;
		long long int p = 1;
		for(long long int i = 1; i <= n; ++i)
		{
			p += i;
		}
		cout << p << endl;
	}

	return 0;
}
