#include <iostream>
#include <string>
#include <fstream>
#include <limits.h>

using namespace std;
typedef unsigned long long int ull;
ull diff;

#define Rmin(a, b)		( (a) < (b) ? (a) : (b) )

ull calc_comb(int n, int k)
{
	int r  = Rmin( n-k, k);
	ull prod = 1;
	for( int i = 1; i <= r; ++i)
	{
		prod = (prod * ( n - r + i))/i;
	}

	if( prod > LONG_MAX)
		prod = 0;

	return prod;
}

int main()
{
	ifstream infile;
	infile.open("./sample.txt");
	int n, k;
	
	while( infile >> n >> k )
	{
		if( !n && !k)
			break;
	
		ull result = calc_comb(n, k);
		printf("%ld\n",result);
	}

	return 0;
}
