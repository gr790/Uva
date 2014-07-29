#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
using namespace std;
void to_dec(string &str)
{
	int len = str.size();
	int value = 0;
	for( int i=len-1; i > 1; --i)
	{
		if( isdigit( str[i]) )
			value += (str[i] - '0') * (long long)pow(16, len-i-1); 
		else if( (str[i] >= 'a') && (str[i] <= 'f') ) 
			value += (str[i] + 10 - 'a') * (long long)pow(16, len-i-1); 
		else if( (str[i] >= 'A') && (str[i] <= 'F') )  
			value += (str[i] + 10 - 'A') * (long long)pow(16, len-i-1); 
	}
	cout << value << endl;
}

int numeric( string &str)
{
	int len = str.size();
	int value = 0;
	for(int i=0; i < len; ++i)
	{
		value = (value * 10) + str[i] - '0';
	}
	return value;
}

void reverse_str( char *s, int start, int end)
{
	if( start < end )
	{
		char tmp = s[start];
		s[start] = s[end];
		s[end] = tmp;
		reverse_str(s, ++start, --end);
	}
}

void to_hex(string &str)
{
	int dec = numeric(str);
	char hex[50] = {0};
	hex[0] = '0';
	hex[1] = 'x';
	int i=2;
	if( dec == 0)
	{
		hex[2] = '0';
		cout << hex << endl;
		return;
	}
	while(dec)
	{
		int rem = dec % 16;
		if( (rem >= 0) && ( rem <= 9))
			hex[i] = rem + '0';
		else if ( (rem >= 10) && ( rem <= 15) )
			hex[i] = 'A' + rem - 10;

		dec = dec / 16;
		i++;
	}
	reverse_str(hex, 2, strlen(hex)-1);
	cout << hex << endl;
}

int main()
{
	string lstr;
	
	while( getline(cin, lstr) )
	{

		if( (lstr[0] == '-') && isdigit(lstr[1]) ) 
			break;

		if( (lstr[0] == '0') && (lstr[1] == 'x') )
			to_dec(lstr);
		else
			to_hex(lstr);
			
	}
	return 0;
}
