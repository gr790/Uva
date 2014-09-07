#include <iostream>
#include <fstream>
#include <map>
#include <math.h>
#include <iomanip>
#include <bitset>
#include <vector>
using namespace std;
#define SIZE 2000000LL
int factors[SIZE+1];

void sieve()
{
	register int i,j,k;
        for(i=2;i<SIZE/2;i++)
        {
                if(!factors[i])
                        factors[i] = 1;
                for(j=2;j<=i&&(k = j*i)<SIZE;j++)
                        if(!factors[k]&&factors[j]==1)
                                        factors[k] = factors[i]+1;
        }
        for(i=2;i<SIZE;i++)
                factors[i] += factors[i-1];

}
int main()
{
	ifstream infile;
	infile.open("./sample.txt");
	sieve();

	int num;
	while( infile >> num )
	{
		map<int, int> freq;
		if( num < 2)
			continue;
		cout << factors[num] << endl;
	}
	return 0;
}

