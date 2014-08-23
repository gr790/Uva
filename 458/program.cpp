#include <stdio.h>
#include <string.h>

int main()
{

	char str[4096] = {0};
	while( scanf("%[^\n]", str) != EOF)
	{
		getchar();
		int len = strlen(str);
		int i=0;
		while(str[i] != '\0')
		{
			str[i] = str[i] - 7;
			i++;
		}

		printf("%s\n", str);
	}

	return 0;
}
