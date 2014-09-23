#include <stdio.h>
#include <string.h>
#include <fstream>
#include <time.h>

void process( int m, int n)
{
   int carry = 0;
   int count = 0;
   while( ((m != 0) && (n != 0)) || carry )
   {
      int dig_m = m % 10;
      int dig_n = n % 10;
          /* count the carry forward also */
      if( (dig_m + dig_n + carry) > 9 )
      {
        count++;
      }
      carry = (dig_m + dig_n + carry ) / 10;
      m = m / 10;
      n = n / 10;
   }
   if( count == 0)
       printf("No carry operation.\n");
   else if( count == 1)
       printf("%d carry operation.\n", count);
   else
       printf("%d carry operations.\n", count);
}

int main()
{
    int m, n;
    freopen("./sample.txt", "r", stdin);
    while( scanf("%d %d", &m, &n) == 2)
    {
       getchar();
       if( (m == 0) && (n == 0) )
          break;
       process(m, n);
    }
    return 0;
}
