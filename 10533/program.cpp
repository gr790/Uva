#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <math.h>

using namespace std;

/* Prime Number */

#define SIZE 1000000LL
bitset<SIZE+1> prime;
int digitprime[SIZE+1];

bool is_sieve_prime(int num)
{
        if( num < 2)
                return false;
        return !prime.test(num);
}

int digit_sum(int num)
{
	int s = 0;
	do
	{
		int rem = num%10;
		s += rem;
		num /= 10;
	}while(num!=0);

	return s;
}

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

	int s = 0;
        for(int i = 2;i <= SIZE; ++i)
        {
                if(!prime.test(i) && is_sieve_prime(digit_sum(i)))
			s++;
		digitprime[i] = s;
		
        }
}


int main()
{
	freopen("./sample.txt", "r", stdin);

	sieve();
	int test;
	scanf("%d\n", &test);
	int lo, up;
	
	while(test--)
	{
		scanf("%d %d\n", &lo, &up);
		printf("%d\n", digitprime[up] - digitprime[lo-1]);
	}
	return 0;
}
