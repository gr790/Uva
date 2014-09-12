#include <stdio.h>
int table[5001][2000] = {0};
void print_fab(int num)
{
   int i;
   int len = table[num][0];
   for(i = len; i >= 1; --i)
      printf("%d", table[num][i]);
   printf("\n");
}
void calc_fab(int i)
{
	int len = table[i-1][0] > table[i-2][0] ? table[i-1][0] : table[i-2][0];
	int carry, tmp,j;
	carry = tmp = 0;
	for(j=1; j <= len; ++j)
	{
		int newdig = table[i-1][j] + table[i-2][j] + carry;
		if( newdig > 9)
		{
			table[i][j] = newdig % 10;
			carry = 1;
		}
		else
		{
			table[i][j] = newdig;
			carry = 0;
		}

		tmp++;
		table[i][0] = tmp;
	}

	if(carry)
		table[i][++table[i][0]] = carry;
}

void pre_cal()
{
	table[0][0] = 1;
	table[0][1] = 0;

	table[1][0] = 1;
	table[1][1] = 1;
	int i;
	for(i=2; i < 5001; ++i)
		calc_fab(i);
}


int main()
{

	pre_cal();
	unsigned int num;
  freopen("./sample.txt", "r", stdin);
	while( scanf("%u", &num) != EOF)
	{
		printf("The Fibonacci number for %u is ", num);
		print_fab(num);
	}

	return 0;
}
