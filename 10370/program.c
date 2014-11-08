#include <stdio.h>

int arr[1001] = {0};
int main()
{
        int c;
        freopen("./sample.txt", "r", stdin);
        scanf("%d", &c);
        int i=0;
        while( i < c )
        {
                int n;
                scanf("%d", &n);
                int k=0, total=0;
                while( k < n)
                {
                        scanf("%d", &arr[k]);
                        total += arr[k];
                        ++k;
                }
                float avg = (float) total / n ;
                int ns=0;
                for(k=0; k < n; ++k)
                {
                        if(arr[k] > avg )
                                ns++;
                }
                printf("%'.3f%\n", (float)(ns * 100) / n );
                ++i;
        }

        return 0;
}

