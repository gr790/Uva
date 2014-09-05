#include <iostream>
#include <string.h>
#include <string>
#include <fstream>

using namespace std;

void to_lower(string &str)
{
	int len = str.size();
	for( int i = 0; i < len; ++i )
		if(isupper(str[i]))
			str[i] = str[i] + 'a' -'A';
}
int main()
{

	int max_len = 0;
	string word;
	char ch;
	string max_word;
	freopen("./sample.txt", "r", stdin);
	int len = 0;
	while( scanf("%c", &ch) != EOF)
	{

		if( isalpha(ch) || ( ch == '-') )
		{
			word += ch;	
			len++;
		}
		if( word == "E-N-D")
			break;


		if( ! isalpha(ch) && ! (ch == '-') ) 
		{
			if( len > max_len )
			{
				max_len = len;
				max_word = word;
			}
			word = "";
			len = 0;
		}
	}

	to_lower(max_word);

	cout << max_word << endl;
	return 0;
}
