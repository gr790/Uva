#include <stdio.h>

int main()
{
	long long int v;
	unsigned long long int t;
	v = t = 0;
	freopen("./sample.txt", "r", stdin);
	while( scanf("%lld %lld", &v, &t) == 2)
	{
		getchar();
		if( (t < 0) || (t > 200) )
			continue;
		if( (v < -100) || ( v > 100) ) 
			continue;
		/* using kinematic motion formula */
		/* d = v*t + 1/2at^2 */
		/* in case if a is constant , a = 0 */
		unsigned long long int t1 = t * 2;
		long long int d = v * t1;
		printf("%lld\n", d);
	}

	return 0;
}
