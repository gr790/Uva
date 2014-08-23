#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char keybd[4][15] = 
		{ 
			{ '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\\' },
			{ 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']' },
			{ 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'' },
			{ 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/' },
		};		

#define Rlo(x)	((x >= 'A' && x <= 'Z') ? (x+32) : x)

int main()
{
	char str[4096];
	freopen("./sample.txt", "r", stdin);
	while( scanf("%[^\n]", str) == 1)
	{
		getchar();
		int len = strlen(str);
		bool found = false;
		for( int i = 0; i < len; ++i)
		{
			found = false;
			char ch = Rlo(str[i]);
			if( ch == '`' || ch == '1' || ch == 'q' || ch == 'w' 
				|| ch == 'a' || ch == 's' || ch == 'z' || ch == 'x') 
				continue;
			for( int j=0; j < 4; ++j) 
			{
				for(int k=2; k < 15; ++k)
				{
					if(Rlo(str[i]) == keybd[j][k])
					{
						str[i] = keybd[j][k-2];
						found = true;
						break;
					}
				}
				if(found)
					break;
			}
		}

		printf("%s\n", str);
	}
	return 0;
}
