#include <stdio.h>
#include <string.h>
#include <math.h>


#define bool int
#define false 0
#define true 1

int arr[1000] = {0};

bool read_string()
{
	char str[1000] = {0};
	scanf("%s", str);
	getchar();

	if( str[0] == '0')
		return false;

	int len = arr[0] = strlen(str);

	int j = 1;
	while( j <= arr[0] )
	{
		arr[j] = str[len - j] - '0';
		j++;
	}
	return true;
}

int calc_value()
{
	int sum = 0;
	
	int j;
	for(j=arr[0]; j >=0; --j)
	{
		sum += (arr[j] * (pow(2,j)-1) );
	}
	return sum;
		
}

int main()
{
  freopen("./sample.txt", "r", stdin);
	while(true)
	{
		bool read_next = read_string();
		if( !read_next)
			break;
		int sum = calc_value();
		printf("%d\n", sum );
	}
	return 0;
}
