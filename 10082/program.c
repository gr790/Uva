#include <stdio.h>
#include <string.h>
#define bool int
#define true 1
#define false 0

char keybd[4][15] = { '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=',
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'', 
		'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/',
		};		
char process(char ch)
{
	int i,j;
	for( i=0; i < 4; ++i) 
	{
		for(j=0; j< 15; ++j)
		{
			if(ch == keybd[i][j])
				return keybd[i][j-1];
		}
	}
	return '\0';
}
bool pre_process( char ch)
{
	if( ch == 'A' || ch == 'Q' || ch == 'Z' || ch == '`')
		return false;

	if( islower(ch)) return false;

	return true;
		
}
int main()
{
	char str[4096];
  freopen("./sample.txt", "r", stdin);
	while( scanf("%[^\n]", str) == 1)
	{
		getchar();
		int len = strlen(str);
		int i = 0;
		while( str[i] != '\0')
		{
			bool is_ok = pre_process(str[i]);
			if(is_ok) 
			{
				char ch;
				ch = process(str[i]);
				if( ch != '\0')
					str[i] = ch;
			}
			++i;
		}

		printf("%s\n", str);
	}
	return 0;
}
