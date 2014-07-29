#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char ch;
	int quote_count = 0;
	while( (ch=getchar()) != EOF)
	{
		switch(ch)
		{
			case '"':
				quote_count ++;
				if( quote_count % 2 != 0) 
				{
					printf("``");
					
				}
				else
				{
					printf("''");
				}
				break;
			default:
				putchar(ch);
				break;
		}
	}
	return 0;
}
