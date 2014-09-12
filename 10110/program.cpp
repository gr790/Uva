#include <stdio.h>
#include <math.h>

int main()
{
	unsigned int n;
  freopen("./sample.txt", "r", stdin);
	while( scanf("%u", &n) == 1)
	{
		if( !n) break;
		int m = (int)sqrt(n);
		if( (m * m) == n)
			printf("yes");
		else
			printf("no");

		printf("\n");
	}
	return 0;
}
