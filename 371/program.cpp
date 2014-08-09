#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
int main()
{
	unsigned long int m, n, max, cnt, temp;
	unsigned long int i, index;
	ifstream infile;
	infile.open("./sample.txt");
	while ( infile >> m >> n )
	{
		if( !m && !n )
			break;
		if (m > n)
		{
			m ^= n;
			n ^= m;
			m ^= n;
		}
		max = cnt = 0;
		for(i = m; i <= n; i++) 
		{
			unsigned long int num = i;
			do
			{
				if (num % 2 == 0)
					num >>= 1;
				else
					num = 3*num+1;
				++cnt;
			}while(num != 1);

			if (cnt > max)
			{
				max = cnt;
				index = i;
			}
			cnt = 0;
		}
		printf("Between %ld and %ld, %ld generates the longest sequence of %ld values.\n",m, n, index, max);
		index = 0;
    	}
	return 0;
}
