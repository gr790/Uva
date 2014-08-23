#include <stdio.h>
#include <string.h>

int main()
{
	char str[1000];

	freopen("./sample.txt", "r", stdin);	
	while( scanf("%s", str) != EOF)
	{
		char c = getchar();
		int len = strlen(str);
		int i;
		for(i=len-1; i >=0; --i)
		{
			printf("%c", str[i]);
		}

		putchar(c);
	}

	return 0;
}
