#include <stdio.h>
#include <stdlib.h>

int main()
{

	unsigned long int a, b;
	a = b = 0;
  freopen("./sample.txt", "r", stdin);
	while( scanf("%ld %ld", &a, &b) != EOF) 
	{
		getchar();
		printf("%ld\n", labs(a-b) );
	}
	return 0;
}
