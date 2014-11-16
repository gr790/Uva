#include <iostream>
#include <fstream>

using namespace std;

int gcd( int a, int b)
{
	if(b == 0 )
		return a;
	else
		gcd(b, a%b);
}

int main()
{
	ifstream infile;
	infile.open("./sample.txt");
	
	int num;
	while( infile >> num )
	{
		if(!num)
			break;
	
		unsigned long int g = 0;
		for(int i = 1; i < num; ++i)
		{
			for(int j = i + 1; j <=num; ++j)
			{
				if( i >= j )
				{
					g += gcd(i,j);
				}
				else
				{
					g += gcd(j, i);
				}
			}
		}
		cout << g << endl;
	}
	return 0;
}
