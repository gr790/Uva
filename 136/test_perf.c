#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define min(a, b) (a) < (b) ? (a) : (b)
#define find_min(a, b, c) min(a, min(b,c))

void ugly_number()
{
        unsigned int ugly[1500] = {0};
	ugly[0] = 1;
	unsigned int pos2, pos3, pos5;

	pos2 = pos3 = pos5 = 0;

	int i;
	for(i=1; i < 1500; ++i)
	{
		while( ugly[pos2] * 2 <= ugly[i-1])
			pos2++;
		while( ugly[pos3] * 3 <= ugly[i-1])
			pos3++;
		while( ugly[pos5] * 5 <= ugly[i-1])
			pos5++;

		int a = ugly[pos2] * 2;
		int b = ugly[pos3] * 3;
		int c = ugly[pos5] * 5;

		ugly[i] = find_min(a, b, c);
        }
        printf("The 1500'th ugly number is %ld\n", ugly[i-1]);
}

int main()
{
    clock_t startm, stopm;
    startm = clock();
    ugly_number();
    stopm = clock();
    printf("%6.3f seconds used by the processor.\n", ((double)stopm-startm)/CLOCKS_PER_SEC);
    return 0;
}
