#include <stdio.h>
int a[3] = {0};
#define MAX	100000
int main()
{
	int n;
	freopen("./sample.txt", "r", stdin);
	scanf("%d", &n);
	int i=0;
	while(i < n)
	{
		int f = 0;
		scanf("%d", &f);
		if( (f < 0) || ( f > 20) )
			continue;
		int j=0;
		int sum = 0;
		while( j < f)
		{
			scanf("%d %d %d", &a[0], &a[1], &a[2]);
			if( a[0] > 100000) continue;
			else if( a[1] > 100000) continue;
			else if (a[2] > 100000) continue;

			sum += (a[0] * a[2]);
			++j;
			a[0] = a[1] = a[2] = 0;
		}
		printf("%d\n", sum);
		++i;
	}
	return 0;
}
