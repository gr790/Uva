#include <iostream>
#include <ctype.h>
#include <string.h>
#include <fstream>
using namespace std;
typedef unsigned int uint;

int num[10000] = {0};
int rev[10000] = {0};
int sum[10000] = {0};

bool validate(string &str, uint base)
{
	bool is_ok = true;
	int len = str.size();
	for(int i=0; i < len; ++i)
	{
	
		if(isalpha(str[i]))
		{
			if( (str[i] + 10 - 'A') >= base)
			{
				is_ok = false;
				break;
			}
		}
		else
		{
			if( (str[i] - '0') >= base)
			{
				is_ok = false;
				break;
			}
		} 
	}
	return is_ok;
}

void reverse(int *num, int *rev)
{
	rev[0] = num[0];
	for(int i=num[0]; i >= 1; --i)
	{
		rev[rev[0]-i+1] = num[i];
	}
}

void BigNumRead(string &str)
{
	int len = str.size();
	num[0] = len;
	
	for(int i=1; i <= len; ++i)
	{
		if ( (str[len-i] >= '0') && (str[len-i] <= '9') )
			num[i] = str[len-i] - '0';
		else
			num[i] = str[len-i] + 10 - 'A';
	}
}

void calc_sum ( int num[], int rev[], uint base)
{
	int len = num[0];
	sum[0] = 0;
	int carry = 0;
	for(int i=1; i <= len; ++i)
	{
		int newdig = ( num[i] + rev[i] ) + carry;
		if( newdig >= base )
		{
			sum[i] = newdig - base;
			carry = 1;
		} 
		else
		{
                       	sum[i] = newdig;
			carry = 0;
		}
		sum[++sum[0]];
	}

	if(carry)
		sum[++sum[0]] = carry;
}

bool is_palin(int sum[])
{
	int len = sum[0];
	int i, j;
	for(i=1,j=len; i < j; ++i,--j)
	{
		if( sum[i] != sum[j] )
			return false;
	}
	return true;
}

void solve(string &str)
{

	int s_base = 15;
	int e_base = 2;
	bool next_base = true;
	for(int i=s_base; i >= e_base; --i)
	{
		next_base = false;
		if( validate(str, i) )
		{
			int count = 0;
			BigNumRead(str);
			if(is_palin(num))
			{
				cout << count;
				if( i != e_base)
					cout <<' ';
				continue;
			}
			while(count < 100)
			{
				count++;
				reverse(num, rev);
				calc_sum(num, rev, i);
				if(is_palin(sum))
				{
					cout << count;
					if( i != e_base)
						cout <<' ';
					next_base = true;
					break;
				}
				
				for(int i=0; i <= num[0]; ++i)
					num[i] = 0;
				for(int i=0; i <= rev[0]; ++i)
					rev[i] = 0;
				for(int i=0; i <= sum[0]; ++i)
					num[i] = sum[i];
				for(int i=0; i <= sum[0]; ++i)
					sum[i] = 0;
			}
		}
		if(!next_base)
		{
			cout <<'?';
			if( i != e_base)
				cout <<' ';
		}
	}
	
}

int main()
{
	string lstr;
	
	while( cin >> lstr )
	{
		solve(lstr);
		cout <<'\n';
		memset(&num, 0, sizeof(num));
		memset(&rev, 0, sizeof(rev));
	}

	return 0;
}
