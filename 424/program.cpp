#include <stdio.h>
#include <string.h>

#define MAX_LINES	100
#define bool int
#define false 0
#define true 1

int arr[101][101] = {0};
int result[1][101] = {0};

bool read_string(int i)
{
	char str[101] = {0};
	scanf("%s", str);
	getchar();

	if( str[0] == '0')
		return false;

	int len = arr[i][0] = strlen(str);

	int j = 1;
	while( j <= arr[i][0] )
	{
		arr[i][j] = str[len - j] - '0';
		j++;
	}
	return true;
}

void calc_sum(int i)
{
	int len = result[0][0] > arr[i][0] ? result[0][0] : arr[i][0] ;	
	int carry = 0;
	
	int j, tmp=0;
	for(j=1; j <= len; ++j)
	{
		int newdig = result[0][j] + arr[i][j] + carry;
		if( newdig > 9) 
		{
			result[0][j] = newdig % 10;
			carry = 1;
		}
		else
		{
			result[0][j] = newdig;
			carry = 0;
		}
		tmp++;
		result[0][0] = tmp;
	}

	if(carry)
		result[0][++result[0][0]] = carry;
		
}

void print_sum()
{
	int i=0;
	int len = result[0][0];
	for(i = len; i >= 1; --i)
		printf("%d", result[0][i]);

	printf("\n");
}

int main()
{
	int i = 0;
	while( i < MAX_LINES)
	{
		bool read_next = read_string(i);
		if( !read_next)
			break;
		else
			calc_sum(i);
		i++;
	}
	print_sum();
	return 0;
}
