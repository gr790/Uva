#include <iostream>
#include <fstream>
#include <math.h>
#include <bitset>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/* Prime Number */

#define SIZE 10000000LL
bitset<SIZE+1> prime;
vector<int> gpf;

void sieve()
{
	int sq = ceil(sqrt(SIZE));
	for(int i = 2; i <= sq; ++i)
	{
		if(!prime.test(i))
		{
			for(int j = i*i; j <= SIZE; j += i)
				prime.set(j,1);
		}
	}
	for(int i = 2;i <= SIZE; ++i)
	{
		if(!prime.test(i))
			gpf.push_back(i);
	}
}

bool is_sieve_prime(int num)
{
	if( num < 2) 
		return false;
	return !prime.test(num);
}
	
int main()
{
	ifstream infile;
	infile.open("./sample.txt");
	sieve();
	int test;
	infile >> test;
	infile.ignore();
	int num;
	int L, H;

	while( test--)
	{
		infile >> L >> H;
		map<int, int> freq;
		int max = 0, index = 0;
		for(int i = L; i <= H; ++i)
		{
			int sq = ceil(sqrt(i));
			int num = i;
	
			if( (num < 10000000 ) && is_sieve_prime(num))
			{
				freq[num]++;
			}
			else
			{
				vector<int>::iterator itpf;
				for(itpf = gpf.begin(); (itpf != gpf.end() && *itpf <= sq); ++itpf)
				{
					int p = *itpf;
					do
					{
						int rem = num%p;
						if(!rem)
						{
							freq[p]++;
							num = num / p;
						}
						else
							break;
					}while(num!=1);
				}
			}
			map<int, int>::iterator it;
			int prod = 1;
			for(it = freq.begin(); it != freq.end(); ++it)
			{
				prod *= (it->second+1);	
			}
			if( prod > max )
			{
				max = prod;
				index = i;
			}
			freq.clear();
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, H, index, max);
	}
	return 0;
}
