#include <stdio.h>
#include <math.h>
#include <fstream>

int main()
{

	int hours;
	int minutes;
	hours = minutes = 0;
	double degree;
  freopen("./sample.txt", "r", stdin);

	while( scanf("%d:%d", &hours, &minutes) == 2)
	{

		if( (hours == 0) && (minutes == 0) )
			break;

		degree = fabs((60 * hours) - (11 * minutes));
		degree = (double)degree/2;
		if( degree > 180)
			degree = 360 - degree; 
		printf("%.3lf\n", degree);
	}
	return 0;
}
