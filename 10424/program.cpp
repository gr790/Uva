#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define R(x)	(( x >= 'A' && x <= 'Z') ? x +32 : x )
#define C(x)	(x - 96)

int sum_dig(int num)
{
	int s = 0;
	while(true)
	{
		int r = num % 10;
		s += r;
		num /= 10;
		if(!num)
		{
			if(s >= 10)
			{
				num = s;
				s = 0;
			}
			else
				break;
		}
	}
	return s;
}

void cal_love(string &s1, string &s2)
{
	int len = s1.size();
	int sum1, sum2;
	sum1 = sum2 = 0;
	for(int i = 0; i < len; ++i)
	{
		char ch = R(s1[i]);
		if( ch >= 'a' && ch <= 'z')
			sum1 += C(ch);
	}

	len = s2.size();
	for(int i = 0; i < len; ++i)
	{
		char ch = R(s2[i]);
		if( ch >= 'a' && ch <= 'z')
			sum2 += C(ch);
	}

	int sd1 = sum_dig(sum1);
	int sd2 = sum_dig(sum2);
	if( sd1 > sd2 )
		printf("%.2f %\n", (sd2*100.00)/sd1 );
	else
		printf("%.2f %\n", (sd1*100.00)/sd2 );
}

int main()
{
	ifstream infile;
	infile.open("./sample.txt");

	string first, second;
	while( getline(infile, first) )
	{
		getline(infile, second);
		cal_love(first, second);
	}
		
	return 0;
}
