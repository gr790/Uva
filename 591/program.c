#include <stdio.h>

int arr[51] = {0};
int main()
{
        int n, set=0;
        freopen("./sample.txt", "r", stdin);
        while( scanf("%d", &n) != EOF)
        {
                if( n == 0)
                        break;
                set++;
                int i=0, sum = 0;
                while( i < n)
                {
                        scanf("%d", &arr[i]);
                        sum += arr[i];
                        i++;
                }
                int avg = (int) sum / n;
                int move = 0;
                for(i=0; i < n; ++i)
                {
                        if( arr[i] > avg)
                                move += arr[i] - avg;
                }

                printf("Set #%d\n", set);
                printf("The minimum number of moves is %d.\n\n", move);
        }

        return 0;
}
