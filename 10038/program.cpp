#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
long int arr[3001] = {0};
#define bool int
bool jolly[3001] = {0};
#define true    1
#define false   0
bool check_jolly(int n)
{
        int i;
        for(i=0; i < n-1; ++i)
        {
                long int diff = labs(arr[i] - arr[i+1]);
                if( diff >= (int)n )
                        return false;
                jolly[diff] = true;
        }

        for(i=1; i < n; ++i)
        {
                if(!jolly[i])
                        return false;
        }
        return true;
}

int main()
{
        int n;
    freopen("./sample.txt", "r", stdin);
        while ( scanf("%d", &n) != EOF)
        {
                int i = 0;
                if(n == 0)
                {
                        printf("Jolly\n");
                        continue;
                }
		
		if( n > 3000)
		{
			long int temp;
			int k = 0;
			while( k < n)
			{
				scanf("%ld", &temp);
				k++;
			}
			continue;
		}

                while( i < n )
                {
                        scanf("%ld", &arr[i]);
                        i++;
                }
                bool is_jolly = check_jolly(n);
                if(is_jolly)
                        printf("Jolly\n");
                else
                        printf("Not jolly\n");

                memset(arr, 0, sizeof(arr));
                memset(jolly, 0, sizeof(jolly));
        }
        return 0;
}
