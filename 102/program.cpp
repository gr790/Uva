#include <stdio.h>

long long int find_min(long long int move[], int n, int *index)
{
	int i = 0;
	long long int min = move[0];
	*index = 0;
	for (i; i < n; ++i)
	{
		if( min > move[i])
		{
			min = move[i];
			*index = i;
		}
	}
	return min;
}
			

void func( long long int min1, long long int min2, long long int *min3)
{
	*min3 = 0;
	switch(min1)
	{
		case 0:
			switch(min2)
			{
				case 1:
					*min3 = 2;
					break;
				case 2:
					*min3 = 1;
					break;
			}
			break;
		case 1:
			switch(min2)
			{
				case 0:
					*min3 = 2;
					break;
				case 2:
					*min3 = 0;
					break;
			}
			break;
		case 2:
			switch(min2)
			{
				case 0:
					*min3 = 1;
					break;
				case 1:
					*min3 = 0;
					break;
			}
			break;
		default:
			break;
	}
}

int main()
{
	long long int b_b1, b_b2, b_b3;
	long long int g_b1, g_b2, g_b3;
	long long int c_b1, c_b2, c_b3;
	long long int bin1[3] = {0}, bin2[3] = {0}, bin3[3] = {0};
	long long int move[6] = {0};
	char bins[6][4] = { "BCG", "BGC", "CBG", "CGB", "GBC", "GCB" };
  freopen("./sample.txt", "r", stdin);
	while( scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld", &b_b1, &g_b1, &c_b1,
			&b_b2, &g_b2, &c_b2,
			&b_b3, &g_b3, &c_b3) == 9)
	{
		bin1[0] = b_b2 + b_b3;
		bin1[1] = c_b2 + c_b3;
		bin1[2] = g_b2 + g_b3;
		bin2[0] = b_b1 + b_b3;
		bin2[1] = c_b1 + c_b3;
		bin2[2] = g_b1 + g_b3;
		bin3[0] = b_b1 + b_b2;
		bin3[1] = c_b1 + c_b2;
		bin3[2] = g_b1 + g_b2;
		int i = 0, j = 0, index = 0;
		while ( i != 3) 
		{
			long long int min1 = i;
			long long int min2 = 0;
			long long int min3 = 0;
			switch(min1) {
				case 0:
					min2 = i + 1; 
					func(min1, min2, &min3);
					move[j] = bin1[min1] + bin2[min2] + bin3[min3];
					min2 = i + 2; 
					func(min1, min2, &min3);
					j++;
					move[j] = bin1[min1] + bin2[min2] + bin3[min3];
					break;
				case 1:
					min2 = i - 1; 
					func(min1, min2, &min3);
					move[j] = bin1[min1] + bin2[min2] + bin3[min3];
					min2 = i + 1; 
					func(min1, min2, &min3);
					j++;
					move[j] = bin1[min1] + bin2[min2] + bin3[min3];
					break;
				case 2:
					min2 = i - 2; 
					func(min1, min2, &min3);
					move[j] = bin1[min1] + bin2[min2] + bin3[min3];
					min2 = i - 1; 
					func(min1, min2, &min3);
					j++;
					move[j] = bin1[min1] + bin2[min2] + bin3[min3];
					break;
			}
			i++; j++;
		}
		long long int movement = find_min(move, 6, &index);
		printf("%s %lld\n", bins[index], movement);
	}
	return 0;
}
