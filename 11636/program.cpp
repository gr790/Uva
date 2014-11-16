#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream infile;
	infile.open("./sample.txt");

	int n;
	int test = 1;
	while( infile >> n )
	{
		if(n < 0)
			break;
		/* initial statement "hello, world" */
		int count = 1;
		int paste = 0;
		if(n == 1) 
			printf("Case %d: %d\n", test, paste); 
		else
		{
			while(1)
			{
				count *= 2;
				if(count >= n) 
				{
					paste++;
					break;
				}
				paste++;
			}
			printf("Case %d: %d\n", test, paste); 
		}
		test++;
	}

	return 0;
}
