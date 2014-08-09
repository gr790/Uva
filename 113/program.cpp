#include <stdio.h>
#include <math.h>

double calc_root(int n, long double p)
{
	return pow(p, (double)1.0/n);
}


int main()
{
	int n;
	double p;
	freopen("./sample.txt", "r", stdin);
	while( scanf("%d", &n) != EOF)
	{
		getchar();
		scanf("%lf", &p);
		double root = calc_root(n, p);
		printf("%.0lf\n", root);
	}

	return 0;
}
