#include <stdio.h>
#include <math.h>
#include <fstream>

#define bool int
#define true 1
#define false 0

bool is_prime(unsigned int num)
{

	int i;
	if( num == 2) return true;
	if( num % 2 == 0) return false;
	
	for(i=3; i <= (int)sqrt(num); ++i)
	{
		if( num % i == 0)
			return false;
	}
	
	return true;
}

unsigned int reverse( unsigned int num)
{
	unsigned int n = 0;
	while(num)
	{
		n = (n * 10) + ( num % 10);
		num = num / 10;
	} 
	
	return n;
}
int main()
{

	unsigned int num;
  freopen("./sample.txt", "r", stdin);
	while( scanf("%u", &num) != EOF)
	{
		if(is_prime(num))
		{
			int r_num = reverse(num);
			if( (r_num != num) && is_prime(r_num))
				printf("%u is emirp.", num);
			else
				printf("%u is prime.", num);
		}
		else
			printf("%u is not prime.", num);
		printf("\n");
	}
	return 0;
}
