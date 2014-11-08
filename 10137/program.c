#include <stdio.h>

double st[1002];
#define MAX_AMOUNT      (double)10000.00
#define bool int
#define true 1
#define false 0

int main()
{
        int ns = 0;
        freopen("./sample.txt", "r", stdin);
        while( scanf("%d", &ns) != EOF)
        {
                if(ns == 0) break;
                int i = 0;
                bool flag = false;
                double sum = 0.0;
                if(ns > 1000) break;
                while(i < ns)
                {
                        scanf("%lf", &st[i]);
                        if( st[i] > MAX_AMOUNT)
                        {
                                flag = true;
                        }
                        sum += st[i];
                        i++;
                }

                if(flag)
                {
                        continue;
                }

                double avg_amount = sum / ns;

                double exchange = 0.0;
                double amount_to_be_paid = 0.0;
                double amount_to_be_get = 0.0;
                i = 0;
                                while(i < ns)
                {
                        long double diff = (double)(long)( (st[i] - avg_amount) * 100.00) / 100.00 ;
                        if( diff < 0)
                        {
                                amount_to_be_paid += diff;
                        }
                        else if( diff > 0)
                        {
                                amount_to_be_get += diff;
                        }
                        i++;
                }
                exchange = (-amount_to_be_paid > amount_to_be_get) ? -amount_to_be_paid : amount_to_be_get;
                printf("$%.2f\n", exchange);
        }
        return 0;
}
