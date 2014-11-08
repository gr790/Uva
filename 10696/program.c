#include <stdio.h>

int f91( int num)
{
	if( num >= 101)
		return num - 10;
	else if( num <= 101)
		f91(f91(num+11));
}
int main()
{
	int num;
	freopen("./sample.txt", "r", stdin);
	while( scanf("%d", &num) != EOF)
	{
		if(num == 0)
			break;

		printf("f91(%d) = %d\n", num, f91(num));
	}

	return 0;
}
