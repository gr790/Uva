#include <iostream>
#include <string>
#include <fstream>
#include <limits.h>

using namespace std;
typedef unsigned long long int ull;
ull diff;

#define Rmin(a, b)		( (a) < (b) ? (a) : (b) )

ull calc_comb(int n, int m)
{
	int r = Rmin( n-m, m);
	
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
	unsigned int N, M;
	
	while( infile >> N >> M )
	{
		if( !N && !M)
			break;
	
		ull result = calc_comb(N, M);
		printf("%d things taken %d at a time is %lld exactly.\n", N, M, result);
	}

	return 0;
}
