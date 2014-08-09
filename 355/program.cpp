#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

typedef unsigned int uint32_t;
typedef unsigned long long int ullong;

bool validate(string &str, uint32_t orig_b)
{
	bool is_ok = true;
	switch(orig_b)
	{
		default:
			{
				int len = str.size();
				for(int i=0; i < len; ++i)
				{
					if( isalpha( str[i]) )
					{
						if( (str[i] + 10 - 'A') >= orig_b)
						{	
							is_ok = false;
							break;
						}
					}
					else
					{
						if( (str[i]-'0') >= orig_b )
						{
							is_ok = false;
							break;
						}
					}
				}
			}
			break;
	}

	return is_ok;
}

ullong old_to_dec( string &str, uint32_t orig_b)
{
	int len = str.size();
	ullong value = 0;
	for(int i=0; i < len; ++i)
	{
		if(( str[i] >= 'a') && (str[i] <= 'f'))
			value += (str[i] + 10 - 'a') * (long long int)pow(orig_b, len-i-1); 
		else if (( str[i] >= 'A') && (str[i] <= 'F'))
			value += (str[i] + 10 - 'A') * (long long int)pow(orig_b, len-i-1); 
		else 
			value += (str[i] - '0') * (long long int)pow(orig_b, len-i-1); 
	}
	return value;
}

void reverse(string &s, uint32_t start, uint32_t end)
{

	if( start < end )
	{
		char tmp = s[start];
		s[start] = s[end];
		s[end] = tmp;
		reverse(s, ++start, --end);
	}
}

void dec_to_new(ullong dec, uint32_t new_b, string &value)
{

	while(dec != 0)
	{
		int rem = dec % new_b;
		if( (rem >= 0) && ( rem <= 9) )
			value += rem + '0';
		else 
			value += 'A' + rem - 10;
		dec = dec / new_b;
	}
	reverse(value, 0, value.length()-1);
	return;
}

void process(string &num, uint32_t orig_b, uint32_t new_b)
{
	string value;
	ullong dec = old_to_dec( num, orig_b);
	
	if( (dec != 0) && (new_b != 10) )
	{
		dec_to_new(dec, new_b, value);
		cout << num <<" base " << orig_b <<" = "<< value <<" base "<< new_b << endl;
	}
	else
		cout << num <<" base " << orig_b <<" = "<< dec <<" base "<< new_b << endl;
}
int main()
{

	uint32_t orig_b, new_b;
	string num, lstr;
	istringstream ss;
  freopen("./sample.txt" , "r", stdin);

	while( getline(cin, lstr) )
	{
		ss.str(lstr);
		
		ss >> orig_b;
		ss >> new_b;
		ss >> num;
	
		bool is_ok = validate(num, orig_b);
		if(!is_ok)
			cout << num <<" is an illegal base " << orig_b <<" number" << endl;
		else
			process(num, orig_b, new_b);

		ss.clear();
		lstr.clear();
	}

	return 0;
}
