#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <limits.h>
#include <map>
#include <bitset>

using namespace std;

#define SIZE 10000000LL
bitset<SIZE+1> prime;

vector<int> gpf;


void sieve(void)
{
	int sq = (int)sqrt(SIZE);
	for(int i = 2; i <= sq; ++i)
	{
		if(!prime.test(i))
		{
			for(int j = (i*i); j <= SIZE; j += i)
			{
				prime.set(j,1);
			}
		}
	}

	for(int i = 2; i <= SIZE; ++i)
	{
		if(!prime.test(i))
			gpf.push_back(i);
	}
}

bool is_prime_seive(int num)
{
	if( num < 2)
		return false;
	return !prime.test(num);
}

void cal_pf(int num)
{
	printf("%d = ", num);
	int sign = 0;
	if( num < 0)
	{
		sign = 1;
		num = -num;
		printf("-1 x ");
	}
	vector<int>::iterator it;
	int sq = (int)sqrt(num);
	for(it = gpf.begin(); (it != gpf.end() && *it <= sq); ++it)
	{
		int rem = 0;
		int p = *it;
		do
		{
			rem = num%p;	
			if(!rem)
			{
				printf("%d",p);
				num = num/p;
				if(num!=1)
					printf(" x ");
			}
			else
				break;
		}while(num!=1);
	}
	if(num!=1)
	{
		printf("%d",num);
	}
}

int main()
{
	ifstream infile;
	infile.open("./sample.txt");
	sieve();
	int num;

	while( infile >> num )
	{
		if(!num) 
			break;

		cal_pf(num);
		cout << endl;
	}
	return 0;
}
