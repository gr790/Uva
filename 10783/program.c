#include <stdio.h>
int calc_sum(int a, int b)
{
	int first_odd;
	int last_odd;
	int sum = 0;
	if( (a%2) == 0)
		first_odd = a | 0x1;
	else
		first_odd = a;

	if ( (b%2) == 0)
		last_odd = b - 1;
	else
		last_odd = b;

	while( first_odd <= last_odd)
	{
		sum += first_odd;
		first_odd += 2;
	}
	return sum;
}
int main()
{
	int t, i = 1;
	int a,b;
  freopen("./sample.txt", "r", stdin);
	scanf("%d", &t);
	getchar();
	if( (t < 1) || ( t > 100) )
		return 0;
	while(i <= t)
	{
		scanf("%d", &a);
		getchar();
		scanf("%d", &b);
		getchar();
		if( (a < 0) || ( a > 100) ) continue; 
		if( (b < 0) || ( b > 100) ) continue; 
		if( a > b ) 
		{
			printf("Case %d: 0\n", i);
		}
		else
		{
			printf("Case %d: %d\n", i, calc_sum(a, b));
		}
		i++;
	}
	return 0;
}
